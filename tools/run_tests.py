#!/usr/bin/env python3
"""Runs the test suite file by file and compares it with the known failures.

Every test file runs in its own mgba-rom-test process (no hydra, so a
hanging test cannot fill the memory). Each test ends up as ok, todo or
fail:
  ok    PASS, KNOWN_FAILING, EXPECTED_FAIL, KNOWN_FAILING_PASS
  todo  TO_DO (upstream placeholders)
  fail  everything else: FAIL, ASSUMPTION_FAIL, INVALID, CRASH, TIMEOUT,
        EXPECTED_FAIL_PASS, HANG (endless emulator output), NO_RESULT
        (the file run ended early)

A failure listed in the baseline (test/known_failures.tsv) is known if
its result, the place of the failing check (file:line) and its reason are
the same; numbers in the reason do not count. The exit status is 1 for
failures that are not in the baseline and for known failures whose
result, place or reason changed.

Usage:
    python3 tools/run_tests.py                    # build, run all, compare
    python3 tools/run_tests.py -j4 test/save.c    # only these files
    python3 tools/run_tests.py --no-build         # reuse the test ELF
    python3 tools/run_tests.py --update-baseline  # write the current failures

With file arguments only those files are compared. --update-baseline
needs a full run. Results: build/jade-test/results/results.tsv and one
log per file. See docs/origin_jade/TESTS.md.
"""

import argparse
import concurrent.futures
import glob
import os
import queue
import re
import resource
import select
import shutil
import signal
import subprocess
import sys
import threading
import time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ELF = "Pokemon_Origin_Jade-test.elf"
BASELINE = "test/known_failures.tsv"
OUT = "build/jade-test/results"
MGBA = "tools/mgba/mgba-rom-test"
PATCHELF = "tools/patchelf/patchelf"

OK_LETTERS = set("PEKU")
TODO_LETTERS = set("T")
# Emulator lines ("GBA: ...") within one test before it counts as hung.
MAX_EMULATOR_LINES = 20000

LINE_RE = re.compile(r"^GBA Debug: :([A-Z])(.*)$")
COLOR_RE = re.compile(r"\x1b\[[0-9;]*m")
# "file:line: reason", "file:line - reason" or a bare "file:line".
LOCATION_RE = re.compile(r"^(\S+:\d+)(?:(?::| -) (.*))?$")
# Numbers in failure reasons; %q of the test runner may print ':' as a digit.
NUMBER_RE = re.compile(r"\d+(?:\.[\d:]+)?")


def test_files():
    """Same list as the Makefile (TEST_SRCS)."""
    files = []
    for pattern in ("test/*.c", "test/*/*.c", "test/*/*/*.c"):
        files += glob.glob(pattern)
    return sorted(f for f in files if ".inc.c" not in f)


def build(jobs):
    cmd = ["make", "BUILD=jade", "TEST=1", ELF, "-j%d" % jobs]
    print("$ " + " ".join(cmd), flush=True)
    if subprocess.run(cmd, cwd=REPO).returncode != 0:
        sys.exit("Building the test ELF failed.")


def patch(elf, *pairs):
    cmd = [PATCHELF, elf] + list(pairs)
    out = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True)
    if out.returncode != 0:
        raise RuntimeError("patchelf failed: " + out.stderr)


def limit_memory(limit):
    def apply():
        resource.setrlimit(resource.RLIMIT_AS, (limit, limit))
    return apply


def run_file(path, elf, timeout, memory):
    """Runs one test file. Returns (results, log text, seconds)."""
    patch(elf, "gTestRunnerArgv", path + "\\0")
    cmd = ["stdbuf", "-oL", MGBA, "-l15", "-ClogLevel.gba.dma=16", "-Rr0", elf]
    start = time.monotonic()
    proc = subprocess.Popen(cmd, cwd=REPO, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            preexec_fn=limit_memory(memory), start_new_session=True)
    results, log = [], []
    name, location, reason, message, emulator_lines, ended = "", "", "", "", 0, None
    # Place and reason of a failed ASSUMPTIONS block of this file.
    assumptions = ("", "")
    pending = b""
    deadline = start + timeout
    while ended is None:
        left = deadline - time.monotonic()
        if left <= 0:
            ended = "TIMEOUT"
            break
        ready, _, _ = select.select([proc.stdout], [], [], min(left, 5))
        if not ready:
            continue
        data = os.read(proc.stdout.fileno(), 65536)
        if not data:
            break
        pending += data
        *lines, pending = pending.split(b"\n")
        for raw in lines:
            line = raw.decode("utf-8", "replace")
            m = LINE_RE.match(line)
            if not m:
                # Last plain debug line, e.g. the message of a failed assertf.
                if line.startswith("GBA Debug: ") and not line.startswith("GBA Debug: in <"):
                    message = line[len("GBA Debug: "):]
                if line.startswith("GBA: "):
                    emulator_lines += 1
                    if emulator_lines > MAX_EMULATOR_LINES:
                        ended = "HANG"
                        break
                    if emulator_lines > 20:
                        continue
                log.append(line)
                continue
            log.append(line)
            letter, text = m.groups()
            if letter == "N":
                # A test, a parametrization or an ASSUMPTIONS block starts.
                name = text
                location, reason, message = "", "", ""
            elif letter == "L":
                where = LOCATION_RE.match(text)
                if not where:
                    location, reason = "", text
                elif where.group(2):
                    location, reason = where.groups()
                    if name == "ASSUMPTIONS: " + path:
                        assumptions = (location, reason)
            elif letter in "PEKUVTAF":
                result = COLOR_RE.sub("", text).strip()
                if letter in OK_LETTERS:
                    location, reason = "", ""
                elif letter == "A" and not reason:
                    location, reason = assumptions
                elif not reason:
                    reason = message
                results.append((name, letter, result, location, reason))
                name, location, reason, message, emulator_lines = "", "", "", "", 0
    if ended is not None:
        try:
            os.killpg(proc.pid, signal.SIGKILL)
        except ProcessLookupError:
            pass
        results.append((name or "(file run)", "F", ended, location, reason))
        log.append("run_tests.py: stopped, " + ended)
    rc = proc.wait()
    if ended is None and rc not in (0, 1):
        results.append(("(file run)", "F", "NO_RESULT", "", "mgba-rom-test exit status %d" % rc))
    return results, "\n".join(log) + "\n", time.monotonic() - start


def status(letter):
    if letter in OK_LETTERS:
        return "ok"
    if letter in TODO_LETTERS:
        return "todo"
    return "fail"


def unique_keys(path, results):
    """(file, name) keys; repeated names in one file get #2, #3, ..."""
    seen = {}
    keyed = []
    for name, letter, result, location, reason in results:
        seen[name] = seen.get(name, 0) + 1
        key_name = name if seen[name] == 1 else "%s #%d" % (name, seen[name])
        keyed.append((path, key_name, letter, result, location, reason))
    return keyed


def clean(text):
    return text.replace("\t", " ").replace("\n", " ").strip()


def signature(location, reason):
    """What a known failure has to keep: the place and the reason without numbers."""
    return location, NUMBER_RE.sub("N", clean(reason))


def describe(location, reason):
    return "%s: %s" % (location, reason) if location else reason


def read_baseline(path):
    """(file, test) -> (result, location, reason)."""
    known = {}
    if not os.path.exists(path):
        return known
    for line in open(path, encoding="utf-8"):
        if not line.strip() or line.startswith("#"):
            continue
        cols = line.rstrip("\n").split("\t") + ["", "", ""]
        known[(cols[0], cols[1])] = (cols[2], cols[3], cols[4])
    return known


def write_baseline(path, failures):
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("# Known test failures of the Origin Jade build, written by\n")
        fh.write("# tools/run_tests.py --update-baseline. Columns: file, test, result,\n")
        fh.write("# place (file:line) and reason of the failing check.\n")
        fh.write("# See docs/origin_jade/TESTS.md before adding entries by hand.\n")
        for f, name, _, result, location, reason in sorted(failures):
            fh.write("\t".join([f, clean(name), result, location, clean(reason)]).rstrip("\t") + "\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("files", nargs="*", help="test files (default: all)")
    parser.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 1)
    parser.add_argument("--no-build", action="store_true", help="use the existing test ELF")
    parser.add_argument("--timeout", type=int, default=900, help="seconds per file (default 900)")
    parser.add_argument("--memory", type=int, default=2048, help="MiB per emulator (default 2048)")
    parser.add_argument("--baseline", default=BASELINE)
    parser.add_argument("--update-baseline", action="store_true", help="write the current failures as the baseline")
    parser.add_argument("--out", default=OUT, help="results directory")
    args = parser.parse_args()

    os.chdir(REPO)
    files = args.files or test_files()
    missing = [f for f in files if not os.path.exists(f)]
    if missing:
        sys.exit("No such test file: " + ", ".join(missing))
    if args.update_baseline and args.files:
        sys.exit("--update-baseline needs a run of all files.")
    for tool in (MGBA, PATCHELF):
        if not os.access(tool, os.X_OK):
            sys.exit("%s is missing; run `make tools` or `make check` once." % tool)
    if not args.no_build:
        build(args.jobs)
    if not os.path.exists(ELF):
        sys.exit(ELF + " is missing; run without --no-build.")

    os.makedirs(os.path.join(args.out, "logs"), exist_ok=True)
    elves = queue.Queue()
    for i in range(args.jobs):
        elf = os.path.join(args.out, "worker%d.elf" % i)
        shutil.copyfile(ELF, elf)
        patch(elf, "gTestRunnerHeadless", "\\x01", "gTestRunnerSkipIsFail", "\\x00",
              "gTestRunnerN", "\\x01", "gTestRunnerI", "\\x00")
        elves.put(elf)

    lock = threading.Lock()
    done = [0]

    def work(path):
        elf = elves.get()
        try:
            results, log, seconds = run_file(path, elf, args.timeout, args.memory << 20)
        finally:
            elves.put(elf)
        with open(os.path.join(args.out, "logs", path.replace("/", "_") + ".log"), "w", encoding="utf-8") as fh:
            fh.write(log)
        with lock:
            done[0] += 1
            fails = sum(status(r[1]) == "fail" for r in results)
            print("[%d/%d] %s: %d tests, %d failing, %.0f s" % (done[0], len(files), path, len(results), fails, seconds), flush=True)
        return unique_keys(path, results)

    # Larger files first, so that the slow ones do not run last.
    order = sorted(files, key=lambda f: -os.path.getsize(f))
    rows = []
    with concurrent.futures.ThreadPoolExecutor(args.jobs) as pool:
        for keyed in pool.map(work, order):
            rows += keyed
    rows.sort()

    with open(os.path.join(args.out, "results.tsv"), "w", encoding="utf-8") as fh:
        fh.write("file\ttest\tstatus\tresult\tlocation\treason\n")
        for f, name, letter, result, location, reason in rows:
            fh.write("\t".join([f, clean(name), status(letter), result, location, clean(reason)]) + "\n")

    failures = [r for r in rows if status(r[2]) == "fail"]
    if args.update_baseline:
        write_baseline(args.baseline, failures)
        print("Baseline written: %s (%d entries)" % (args.baseline, len(failures)))

    known = read_baseline(args.baseline)
    if args.files:
        known = {k: v for k, v in known.items() if k[0] in files}
    failing = {(f, clean(n)): (result, location, reason) for f, n, _, result, location, reason in failures}
    new, changed = [], []
    for k in sorted(failing):
        result, location, reason = failing[k]
        if k not in known or known[k][0] != result:
            new.append(k)
        elif signature(known[k][1], known[k][2]) != signature(location, reason):
            changed.append(k)
    fixed = sorted(k for k in known if k not in failing)

    counts = {"ok": 0, "todo": 0, "fail": 0}
    for r in rows:
        counts[status(r[2])] += 1
    print("\n%d tests in %d files: %d ok, %d todo, %d failing (%d known, %d new, %d changed)"
          % (len(rows), len(files), counts["ok"], counts["todo"], counts["fail"],
             counts["fail"] - len(new) - len(changed), len(new), len(changed)))
    if fixed:
        print("%d known failures pass now or are gone; run --update-baseline:" % len(fixed))
        for f, name in fixed[:20]:
            print("  %s: %s" % (f, name))
        if len(fixed) > 20:
            print("  ... see %s" % os.path.join(args.out, "results.tsv"))
    if changed:
        print("KNOWN FAILURES WITH ANOTHER PLACE OR REASON (%d):" % len(changed))
        for k in changed:
            print("  %s: %s\n    was %s\n    now %s" % (k[0], k[1], describe(*known[k][1:]), describe(*failing[k][1:])))
    if new:
        print("NEW FAILURES (%d):" % len(new))
        for k in new:
            note = " (was %s)" % known[k][0] if k in known else ""
            print("  %s: %s: %s%s" % (k[0], k[1], failing[k][0], note))
    return 1 if new or changed else 0


if __name__ == "__main__":
    sys.exit(main())
