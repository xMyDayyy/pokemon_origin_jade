# Origin Jade - patch series of the audit round

This file describes the patch series of the audit round of 2026-10-30/31:
how it was made, which commits depend on each other, how each commit was
verified and how to apply it. What changed for players is in
`docs/origin_jade/CHANGELOG.md`, what is still open in
`docs/origin_jade/BETA_READINESS.md`.

- **Range:** `3525d22e71..audit`, 144 commits, plus 6 documentation commits
  on top (this file is one of them), 150 in all. `3525d22e71` was the tip
  of `balancing` when the audit started.
- **Commit ids:** all ids (shas) in this file are those of the integration
  branch `audit` in the integration clone. Applying the series with
  `git am` or a rebase gives new ids; the content stays the same.
- **Author and committer** of every commit: xMyDayyy. Commit messages are
  German and describe the change, the files and the effect.
- **Finding ids** in the list below: `A01`-`A122` from the audit's
  inventory, `T-<cluster>-<n>` from the line-by-line deep review,
  `W-<tool>-<n>` from the tool runs, `N-<package>-<n>` from the open points
  of the waves. Their evidence lives in the audit reports, outside the
  repository; `BETA_READINESS.md` repeats the open ones with their
  evidence.

## How the series was made

1. **Inventory.** An audit of `3525d22e71` in 13 phases (story per region,
   systems, data, saves, build and tests) produced the findings `A01`-`A122`
   with evidence, severity and a proposal each.
2. **Wave 1 (83 commits).** Eleven fix packages, each in its own branch
   and worktree (`wp-<package>`) from `3525d22e71`: `kanto_maps`,
   `johto_story`, `hoenn`, `facilities`, `pokemon`, `balance`, `nuzlocke`,
   `randomizer`, `challenge`, `build_tools`, `tests`. Every package was
   reviewed; the review fixes were folded into the commits they belong to
   (autosquash), and every commit was built and checked on its own. After
   the owner decisions of 2026-10-30 the package `starters` (all nine
   starters wild) and one commit for the debug menus were added. The
   packages were then integrated onto `audit` one after the other, which
   gave them new commit ids.
3. **Wave 2 (21 commits).** Small fixes without an owner decision from the
   open points of wave 1, and the map checker `tools/check_maps.py`
   (7 commits), committed on `audit`.
4. **Deep review and tool runs.** Seven clusters were read line by line and
   cross-checked; the map checker, a progress simulator, text width
   measurements, a boss moveset simulation and a core/save review ran on
   the integrated state. They produced the `T-` and `W-` findings.
5. **Wave 3 (40 commits).** Fix packages `w3_hoenn`, `w3_kanto`,
   `w3_johto`, `w3_nuzlocke` and `w3b` (Hall of Fame, clock) for those
   findings, and three tools (`check_game_text`, `check_save_safety`,
   `simulate_progress` with `oj_world`). Each package was reviewed and
   fixed up before integration.
6. **Documentation (6 commits).** D-017 budget numbers, this file,
   `CHANGELOG.md`, `BETA_READINESS.md`, `TESTS.md` and `README.md`.

Rules every commit follows: one finding (or a tight group of the same
kind) per commit; `DECISIONS.md` changes in the same commit as the
behaviour it describes; new flags and vars only in
`include/constants/flags_origin_jade.h` and `vars_origin_jade.h`, at the
next free id of their section; no save migrations (owner decision
2026-10-30: old saves are out of scope); no English game text; code
comments in English.

## Order and dependencies

Apply the series as one block in the listed order. The packages touch
mostly different files, but nearly all of them edit
`docs/origin_jade/DECISIONS.md`, so moving a commit across packages makes
the patches conflict there. Inside the series these orders are required:

- **Flag and var allocations** (next free id of their section, so the
  numbers depend on the order):
  `38cea6c78f` `FLAG_HOENN_RECEIVED_HM_SURF` (Hoenn section + 14),
  `99406ad67c` `FLAG_HOENN_RECEIVED_HM_ROCK_SMASH` and
  `FLAG_HOENN_RECEIVED_REVIVED_FOSSIL_MON` (+ 15, + 16),
  `24f9f86e81` `FLAG_HOENN_RECEIVED_HM_STRENGTH` (+ 17; it also moves the
  static assert on the last Hoenn flag in `src/event_data.c`),
  `df79e21ae3` `VAR_HOENN_SAFARI_ZONE_STATE` (`OJ_VARS_HOENN` + 18),
  `e30f4f495e` `FLAG_HATCHED_TOGEPI_EGG` (`OJ_FLAGS_JOHTO` + 15).
  `ed9d3eaf11` moves `FRLG_FLAGS_RESERVE_START` and adds check 7 of
  `tools/check_flags.py` (reserve markers).
- **DECISIONS entries.** New ids were given in integration order: D-044
  and O-024 (`0b265d9f0f`), D-045 and O-025 (`130c5adb25`), O-026 to O-028
  (`1f0a14655c`; O-026 and O-027 resolved by `321f7eb411` and
  `dbb71e3ec6`), D-046 (`dca90ec7e8`, extended by `c64f0a28dd` and
  `be6aabb11a`). D-017, D-023, D-029, D-040 and D-045 are edited by many
  commits.
- **Save layout.** `0b265d9f0f` grows SaveBlock3 from 992 to 1008 bytes
  (`trainerHillTimesHoenn` at its end). `78aa81bd8e` pins the SaveBlock3
  offsets with `STATIC_ASSERT`s and sets the sizes in `test/save.c`; it was
  written on the base and still expects 992. `c441d676ef` sets 1008 and
  pins the new field. Between these two commits the SaveBlock3 size test
  in `test/save.c` fails (the ROM builds); from `c441d676ef` on it passes.
- **Baselines.** `6586e2c42a` creates `tools/warnings_baseline.txt`,
  `000c8fd011` removes one entry. `631abb6cca` creates
  `test/known_failures.tsv`; its places are file:line, so a later commit
  that moves lines of a test file with known failures must update it.
  `2174699385` adds the S.S. Aqua entry to the `KNOWN_ERRORS` of
  `check_merge.py`, `9c984c84a9` removes it together with the data fix.
- **Build.** `dca90ec7e8` (only Origin Jade is built) comes before
  `a545d4e73a`, `c64f0a28dd` (the CI calls `make`) and `be6aabb11a`
  (`DISABLED_ON_RELEASE` relies on `make release` building Jade).
- **Shared scripts and functions.** `ee688ea031` adds
  `Common_EventScript_AskNicknameGiftPartyMon` and `...GiftBoxMon`, which
  `de88177172`, `2077bf9dbe`, `551f9a1327` and `ed568069c4` call.
  `28158c0e9d` adds `giveitem_norandom`. `93f7a7c67a` adds
  `RandomizeGiftEggMon`, which `e30f4f495e` relies on. `0b265d9f0f` adds
  `GetPrizeMoney`, which `2d84ddaa50` calls from another place. `8dede143ee` (`oj_world.py`)
  comes before `c415155a59` (the simulator imports it). The map checker
  commits `bbe30578ea` to `63ef906433`, the text tool commits
  `a81e0f6dad` to `b887df3606` and the save tool commits `9ea6ff6d2d`,
  `46be3a9de6` build on each other.
- **Same lines in the same file** (swapping them makes the patches
  conflict): `data/scripts/hoenn_arrival.inc` (`ffa85af6e0`, `84a564e935`,
  `f85a38c16f`, `638ad542b2`, `2c6403fa2d`, `63e06c1ef7`);
  `data/maps/NewBarkTown_Lab_hns/scripts.inc` (`80b60b17ac`, `4d8cf66d21`,
  `e30f4f495e`, `2077bf9dbe`); the Nuzlocke end of battle in
  `src/battle_main.c` (`1d8451f15c`, `ac46dd2994`, `d05aa4864f`,
  `321f7eb411`); `src/randomizer.c`, `src/challenge_menu.c` and
  `src/nuzlocke.c` within their packages; `src/trainer_hill.c`
  (`0b265d9f0f`, `2d84ddaa50`); `data/maps/IlexForest_hns/scripts.inc`
  (`28cbfca6b4`, `63f7024435`, `ac408421ec`); `src/field_specials.c`
  (`66c8c9114f`, `d30437a99d`, `488df2564a`); `src/save.c`, `test/save.c`
  (`78aa81bd8e`, `c441d676ef`).
- **Debug state.** `src/data/debug_kanto_complete.h` is not changed by the
  series; `python3 tools/make_kanto_complete.py --check` reports it up to
  date at the tip (2026-10-31).

## Verification per commit

Every commit was built (`make jade -j3` on the package branches, `make -j2`
later; both build the same Jade ROM) and checked with
`python3 tools/check_flags.py` (0 problems). The logs are kept in the
audit workspace, not in the repository.

| Part | Commits | Per-commit build and `check_flags` | Logs |
|---|---:|---|---|
| Wave 1 | 83 | On the package branches before integration: every commit of 10 packages (76 commits) built and checked; `build_tools` gave a byte-identical ROM over all 10 commits. `pokemon` (2 data commits), `starters` (4) and the debug menu commit: only builds of the package or of the integration. After integration (new ids) the wave-1 commits were not rebuilt one by one; the integrated tips were (build 0, `check_flags` 0, debug header up to date). | package reports, `*_percommit*.log`, `review_*_pc_*.log`, `integ_build1.res`, `integ_build2.res`, `integ_b4.res` |
| Wave 2 | 21 | 21 of 21 `make=ok`, `check_flags` 0, with the ids of `audit` | `percommit_wave2.log` |
| Wave 3 | 40 | 40 of 40 `make=ok`, `check_flags` 0, with the ids of `audit` | `percommit_w3.log` |
| Tip `b62f22e381` | 144 | `make` 0, ROM SHA-1 `5c1c08ae7685bf6073ea20c7f87df981d6488c2a`, `check_flags` 0, `check_budget.py`, `check_text_width.py`, `make_kanto_complete.py --check`, test suite with `tools/run_tests.py`: 0 new and 0 changed failures | `integ_b8.res`, `integ_tests_b8.log` |
| Documentation | 6 | each commit: `make -j2` 0, ROM SHA-1 unchanged, `check_flags` 0 | `abschluss/work/repo_docs/` (full and release builds), `abschluss/work/crosscheck/percommit_docs.log` (per commit, final ids) |

On 2026-10-31 the tip was also built from scratch in a fresh worktree
(all 397 C files compiled): the ROM has the same SHA-1 as above, and
`tools/check_warnings.py` finds 105 warnings, as many as the baseline.

## How to apply

The series sits on `3525d22e71`. Two ways:

**Fast-forward** (keeps the commit ids), if `balancing` is still at
`3525d22e71`:

    git fetch <integration clone> audit       # with the doc commits on top
    git checkout balancing
    git merge --ff-only FETCH_HEAD

**Patches** (`git am`), e.g. when `balancing` has moved on:

    # in the integration clone
    git format-patch 3525d22e71..audit -o patches/audit/
    # the doc commits are exported separately, base audit: patches/docs/
    # in the target repository
    git checkout balancing
    git am --3way patches/audit/*.patch patches/docs/*.patch

`git am` keeps author, author date and message; the committer date and so
the commit ids change. The per-package exports of the waves
(`patches/<package>/`) hold the versions before integration and are not
meant for applying; use the export of the whole branch.

After applying, run:

    make -j$(nproc)
    python3 tools/check_flags.py
    python3 tools/make_kanto_complete.py --check
    python3 tools/check_budget.py
    python3 check_merge.py
    python3 tools/run_tests.py

If the target branch has new commits, also run the static tools of
`docs/origin_jade/TESTS.md` (`tools/check_maps.py`,
`tools/simulate_progress.py --hoenn-ticket`).

## Full list in order

The number is the position in the series; the title is the commit title
(German, as in git).

### Wave 1

#### `kanto_maps`: Kanto maps and warps

| # | Commit | Title | Findings |
|---:|---|---|---|
| 1 | `bf4d84843d` | Prismania City: Türen wieder auf allen Warps | A01, W-map_checker-1, W-progress_sim-1 |
| 2 | `75c85591c8` | Route 8: Torhaus nach Saffronia von Westen wieder betretbar | A12, W-map_checker-3 |
| 3 | `49aa20ab68` | Mondberg B3F: Weg zur Mew-Kammer begehbar | A11, W-map_checker-2, W-progress_sim-2 |
| 4 | `2df90d157b` | Kanto: drei Warps auf auslösbare Felder gelegt | T-kanto_a-3, T-kanto_a-4, W-map_checker-4 |
| 5 | `0124707dc7` | Lavandia: Obergeschoss des Pokémon-Centers mit dem richtigen Layout | W-map_checker-5 |
| 6 | `0dacb0557a` | Route 9: Itemball mit TM40 (Aero-Ass) erreichbar | A47, W-map_checker-5, W-progress_sim-3 |
| 7 | `6b20e81d4a` | make_kanto_complete: Pikachu-Doktor nicht mehr als fehlend gemeldet | A71 |
| 8 | `e3dcdf00eb` | Marmoria City: Laufschuh-Trigger nach Rocko nur noch einmal | A49 |
| 9 | `cbb0a9a2ca` | Safari-Zone (Kanto): Randblöcke wieder vollständig | A39, A98, W-map_checker-5 |
| 10 | `425eb2fbb1` | Route 10, 17, 19: im HnS-Merge verlorene Layout-Änderungen zurück | N-kanto_maps-2 |
| 11 | `b4a8ab9ce9` | DECISIONS: Zertrümmerer auf der Siegesstraße, Route22_hns in O-022 | A50, A104 |

#### `johto_story`: Johto story state

| # | Commit | Title | Findings |
|---:|---|---|---|
| 12 | `28cbfca6b4` | Johto: GS-Ball als Basis-Item, Celebi-Schrein verlangt ihn | A02, A52 |
| 13 | `80b60b17ac` | Johto: Theater-Zustand läuft nur noch vorwärts | A03, T-kanto_b-5 |
| 14 | `89f7c83d03` | Johto: Azalea nimmt die VM Surfer aus Kanto nicht mehr weg | A13 |
| 15 | `4d8cf66d21` | Johto: PokéCom-„Zustand“ auch, wenn Lind von links angesprochen wird | A53 |
| 16 | `35b99a0b2a` | Johto: Rote Haut geht bei vollem Beutel nicht mehr verloren | A57 |
| 17 | `ae4b56e8e8` | Torhaus: Weg nach Johto erst mit Eichs GS-Ball | A102 |
| 18 | `c16463afb7` | Kampfzone: Mogelbaum lässt sich mit der Schiggykanne wecken | A65 |
| 19 | `06befcd4c6` | DECISIONS: Strudel und Rückweg aus Neuborkia in D-008 festgehalten | A51, A106 |

#### `hoenn`: Hoenn arrival and story

| # | Commit | Title | Findings |
|---:|---|---|---|
| 20 | `ffa85af6e0` | Hoenn: Schiffsfahrten setzen die Hoenn-Story nicht mehr zurück | A04, A14 |
| 21 | `84a564e935` | Hoenn: Respawn bei der Ankunft, Birks Empfang wird nachgeholt | A64 |
| 22 | `f85a38c16f` | Hoenn: keine M.S.-Ticket-Szene in Wurzelheim nach dem Titel | A05 |
| 23 | `a242593207` | Hoenn: Birks Szene „Nationaler Modus“ nach dem Titel entfällt | A58 |
| 24 | `97954fcd88` | Hoenn: Maikes Musik auch für Spielerinnen | A60 |
| 25 | `638ad542b2` | Hoenn: Fliegen zur Pokémon-Liga in Prachtpolis City | A59 |
| 26 | `3c4a70b8d1` | Hoenn: Mädchen im Wettbewerbs-Foyer erkennt die Pokériegelbox | A62 |
| 27 | `38cea6c78f` | Hoenn: eigenes Surfer-Flag für Wallys Eltern | A55, A61 |
| 28 | `99406ad67c` | Hoenn: Zertrümmerer-Mann und Fossilmaniac mit eigenen Flags | A61 |
| 29 | `df79e21ae3` | Hoenn: Safari-Zone mit eigenem Zustand, Ausgang wieder auf Route 121 | A61 |
| 30 | `2c6403fa2d` | Hoenn: Schiffsankunft nicht mitten in Adrians Szene im Hafen | A04, A14 |

#### `facilities`: Battle Frontier and Trainer Hills

| # | Commit | Title | Findings |
|---:|---|---|---|
| 31 | `d0324da2bf` | Kampfzone und Trainerberg: keine deaktivierten Arten mehr in den Teams | A18 |
| 32 | `0b265d9f0f` | Hoenn: Trainerberg auf Route 111 mit Emerald-Trainern statt leerer Etagen | A15, A29 |

#### `pokemon`: Pokemon availability

| # | Commit | Title | Findings |
|---:|---|---|---|
| 33 | `548c6a1eb1` | Hoenn: Meditie und Meditalis wieder wild (Pyroberg, Siegesstraße) | A16 |
| 34 | `d1dfc29263` | DECISIONS: O-009 um gesperrte Inhalte mit deaktivierten Arten ergänzt | A70, A76, A117 |

#### `starters`: all starters wild (owner decision 2026-10-30)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 35 | `51b8d58b8c` | Kanto: Bisasam, Glumanda und Schiggy auch nachts mit 5 % | A17 |
| 36 | `ecf36a7f03` | Johto: Endivie, Feurigel und Karnimani wild mit 5 % | A17 |
| 37 | `dc7c95072c` | Hoenn: Geckarbor, Flemmli und Hydropi mit 5 % statt 1 % | A17 |
| 38 | `8167ea7bc6` | Route 26 und 27: Overworld-Pokémon zeigen fangbare Arten statt Starter | A66 |

#### `balance`: level scaling and battle partners

| # | Commit | Title | Findings |
|---:|---|---|---|
| 39 | `cc1c3ed002` | Levelcap-Challenge: Kanto-Tabellen passend zur Leiter | A28 |
| 40 | `4df138907f` | Kampfpartner: Troy und Siegfried statt STEVEN und LANCE | A115, W-text_width-21 |
| 41 | `167979e1c0` | HnS-Trainerinnen: Geschlecht weiblich bei Arenaleiterinnen und Co. | A116 |
| 42 | `2353317f2f` | Kampfpartner skalieren mit: Troy und Siegfried auf Spielerniveau | A21 |
| 43 | `22896141f1` | Johto: Dukatia und Teak bis zur Story-Wende mit Decke 53 | A73 |
| 44 | `9cd7d8f439` | Johto: Telefon-Rückkämpfe mit mindestens drei Pokémon | A72 |

#### `nuzlocke`: Nuzlocke rules

| # | Commit | Title | Findings |
|---:|---|---|---|
| 45 | `130c5adb25` | Nuzlocke endet mit dem ersten Hoenn-Titel statt mit Rot | A23 |
| 46 | `1d8451f15c` | Nuzlocke: Kämpfe ohne Fangmöglichkeit verbrauchen das Gebiet nicht | A25 |
| 47 | `ac46dd2994` | Nuzlocke: Shiny-Klausel verbraucht die erste Begegnung nicht mehr | A83 |
| 48 | `d05aa4864f` | Nuzlocke: Tod auch in Kämpfen mit KI-Partner | A30 |
| 49 | `df06d73321` | Nuzlocke: Niederlage überschreibt keine Eier mehr | A79 |
| 50 | `ee688ea031` | Nuzlocke: Spitznamenpflicht auch für Kantos Geschenk-Pokémon | A87 |
| 51 | `1f0a14655c` | DECISIONS: offene Nuzlocke-Punkte zu Statics, Eiern und Trainerberg | A26, A118 |

#### `randomizer`: randomizer

| # | Commit | Title | Findings |
|---:|---|---|---|
| 52 | `28158c0e9d` | Item-Randomizer: ab dem ersten Starter aktiv, auch in Kanto | A24 |
| 53 | `013fb23c59` | Item-Randomizer: versteckte Items einzeln, Karte im Seed richtig herum | A88 |
| 54 | `d989ed8f85` | Item-Randomizer: Fossilien und Entwicklungs-Items bleiben an ihrem Platz | A120 |
| 55 | `8d16c9177e` | Trainer-Randomizer: Seed je Trainer statt je Trainerklasse | A80 |
| 56 | `69bf221161` | Feste PKMN: Ausnahmen wie im Menü, feste Seeds, Starter wie Vorschau | A27 |
| 57 | `93f7a7c67a` | Feste PKMN: nur Geschenk-Eier zufällig, Pensions-Eier bleiben | A77 |
| 58 | `998ceca95f` | VM-Notlösung auch bei allen Arten-Randomizern | A119 |

#### `challenge`: challenge menu

| # | Commit | Title | Findings |
|---:|---|---|---|
| 59 | `6355102c85` | Super teuer!: Verkaufspreis wieder vom Grundpreis | A81 |
| 60 | `2d0444d19c` | Weniger Flucht: Fluchtchance nach Initiative statt pauschal 50 % | A82 |
| 61 | `0b35c1bde2` | Challenge-Menü: RNG nur beim neuen Spiel aus den Timern säen | A84 |
| 62 | `5ee30d9a40` | Ein-Typ-Challenge: Standard explizit aus, genullte SaveBlock3 gilt als aus | A45 |
| 63 | `cd86b6c21a` | Dukatia Blumenladen: Minzverkäuferin spricht Deutsch | A86, W-text_width-21 |
| 64 | `a1d638b38f` | Natur-Minzen „Aus“: Verkauf ab dem ersten Hoenn-Titel | A85 |
| 65 | `d4770f4d8f` | Zufallsmodus: Zeile „Legendäre“ nur ohne Ausgleich wählbar | A85 |
| 66 | `a6bb899765` | Challenge-Menü: Beschreibungen passend zur Umsetzung | A85 |

#### `build_tools`: build, CI and check tools

| # | Commit | Title | Findings |
|---:|---|---|---|
| 67 | `dca90ec7e8` | Build: nur noch Origin Jade, make und make check bauen Jade | A36, A43 |
| 68 | `51e8c2d135` | Build: make clean entfernt die Jade-ROM und alle Build-Verzeichnisse | A41 |
| 69 | `5ebf0cb597` | Werkzeug: check_pokenav_text.py liest die Glyphbreiten ab Index 0 | A34, A90 |
| 70 | `2174699385` | Werkzeug: check_merge.py ohne Fehlalarme, bekannte Fälle mit Begründung | A39, A91 |
| 71 | `e348ff39bb` | Werkzeug: Textbreiten der gebauten ROM messen, Textschuld neu bewertet | A34, A90 |
| 72 | `fd95e149f0` | Werkzeug: Save- und Speicherbudget nach dem Build ausgeben | A38 |
| 73 | `6586e2c42a` | Werkzeug: Compiler-Warnungen gegen eine feste Liste prüfen | A99, A100 |
| 74 | `a545d4e73a` | Build: teachable_learnsets.h folgt der GAME_VERSION | A42 |
| 75 | `8e41cc9191` | Doku: INSTALL.md baut mit make statt make hns | A46 |
| 76 | `c64f0a28dd` | CI: ein Jade-Workflow statt der Upstream-Jobs | A36, A37, A92 |

#### Debug menus (owner decision 2026-10-30, added at integration)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 77 | `be6aabb11a` | Debug-Menüs: in der Beta an, in make release aus | A09, A22, A33 |

#### `tests`: test suite and save layout guards

| # | Commit | Title | Findings |
|---:|---|---|---|
| 78 | `c68220b18f` | Tests: fake_rtc.h bindet global.h selbst ein, Test-Runner kompiliert | A06, A31 |
| 79 | `a0e623d5ea` | Tests: Testumgebung startet wie ein neues Spiel, Ballwurf hängt nicht mehr | A07 |
| 80 | `ed9d3eaf11` | Flags: Nummern ohne Speicher erkennen, Reservemarke FRLG hinter S.S. Aqua | A39, A44, A96 |
| 81 | `78aa81bd8e` | Speicherlayout: Wächter für Trainerfenster, SaveBlock3 und Testgrößen | A89, A93, A95, A97 |
| 82 | `17cb0ed51e` | Tests: Origin-Jade-Tests für Level-Skalierung und Flag-/Var-Umleitung | A10 |
| 83 | `631abb6cca` | Tests: run_tests.py mit Liste bekannter Fehlschläge als Regressionstest | A08, A32, A94 |

### Wave 2

#### Small fixes (1)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 84 | `030660c91d` | Johto: deutsche Namen für Rückkampfstufen, Rot und Pyramidenkönig | W-text_width-21, N-balance-2 |
| 85 | `a142e01c51` | Rocket-Versteck: deutsche Niederlagentexte im Doppelkampf mit Siegfried | W-text_width-21, N-balance-3 |
| 86 | `ecba0eaa87` | Radioturm: Quizgewinn setzt den Dukatia-Status nicht mehr zurück | T-johto_b-3 |

#### `map_checker`: `tools/check_maps.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 87 | `bbe30578ea` | Werkzeug: statische Kartenprüfung tools/check_maps.py | - |
| 88 | `245a1302de` | Kartenprüfung: Höhen, Fahrten und Kartenwechsel genauer bewertet | - |
| 89 | `3823921744` | Kartenprüfung: Spielerbewegungen aus Coord-Events nachgezogen | - |
| 90 | `846613507a` | Kartenprüfung: Bewertung bekannter Muster nachgeschärft | - |
| 91 | `ca2b081d19` | Kartenprüfung: Vergleich mit einem früheren Stand (--compare) | - |
| 92 | `8215548626` | Kartenprüfung: Textblöcke beenden Skripte, Ausgabe reproduzierbar | - |
| 93 | `63ef906433` | Kartenprüfung: Kartenreste von Layoutwechseln als "optional" | - |

#### Small fixes (2)

| # | Commit | Title | Findings |
|---:|---|---|---|
| 94 | `6faac92fe4` | Kanto: drei versteckte Items mit passender Höhe wieder auffindbar | W-map_checker-6, W-map_checker-7, W-map_checker-8 |
| 95 | `fc4265e4bf` | Siegesstraße 2F (Kanto): Trank auf ein erreichbares Feld | W-map_checker-9, W-progress_sim-3 |
| 96 | `22adbd2c6d` | Kanto: Mama nennt nach einer Niederlage Prof. Eich statt Prof. Birk | T-kanto_a-1 |
| 97 | `6fa1cfe509` | Azuria: Orden-Erklärer nennt die Gehorsamsgrenzen von Origin Jade | T-kanto_a-2 |
| 98 | `89d8e2c60d` | Route 36: Frage zur Schiggykanne passt in die Textbox | W-text_width-20 |
| 99 | `321f7eb411` | Nuzlocke: statische Begegnungen sind frei und immer fangbar | A26 |
| 100 | `dbb71e3ec6` | Nuzlocke: Eier schlüpfen immer und verbrauchen kein Gebiet | A118 |
| 101 | `c441d676ef` | Tests: SaveBlock3-Größe mit den Rekorden des Hoenn-Trainerbergs | A93 |
| 102 | `2d84ddaa50` | Trainerberg Route 40: Preisgeld nur zusammen mit dem Preis | N-facilities-1 |
| 103 | `9c984c84a9` | M.S. Aqua 1F: Tür-Warp zeigt auf den vorhandenen Hafen-Warp | A39, W-map_checker-14 |
| 104 | `000c8fd011` | Nuzlocke: ungenutzte Variable entfernt | N-challenge-2 |

### Wave 3

#### `w3_hoenn`: Hoenn

| # | Commit | Title | Findings |
|---:|---|---|---|
| 105 | `52695b73f8` | Xeneroville: Wassili gibt VM Kaskade, wenn sie fehlt | T-hoenn_b-3 |
| 106 | `66c8c9114f` | Wetterinstitut: Wetterbericht nennt die richtige Hoenn-Route | T-hoenn_b-1 |
| 107 | `d30437a99d` | Wetterereignis: Ende auf der Hoenn-Route statt in Kartengruppe 0 | T-hoenn_b-2 |
| 108 | `eb6b5a1a66` | Blütenburg City: Szene des Arena-Jungen läuft nur einmal | T-hoenn_a-5 |
| 109 | `601bf4bb9a` | Arena Blütenburg City: geschlossene Arena auch mit 1-3 Orden verlassen | T-hoenn_a-6 |
| 110 | `5eb145e6a7` | Malvenfroh City: nach dem Kampf steht Heiko nicht mehr in Blütenburg | T-hoenn_a-4 |
| 111 | `24f9f86e81` | Hoenn: Stärke und Blitz setzen keine Johto-Flags mehr | T-hoenn_a-8 |
| 112 | `63e06c1ef7` | Wurzelheim: Ortsbewohner mit dem PC-Hinweis bleibt sichtbar | T-hoenn_a-11 |
| 113 | `488df2564a` | Normans Anruf zur Arenaöffnung klingelt nur in Hoenn | T-hoenn_a-9 |
| 114 | `7192e23ba7` | Metarost City: Schneider-Haus bricht den Dialog nicht mehr ab | T-hoenn_a-7 |

#### `w3_kanto`: Kanto

| # | Commit | Title | Findings |
|---:|---|---|---|
| 115 | `df6c6afbdc` | Zinnober-Labor: Domfossil nach Helixfossil und Altbernstein belebbar | T-kanto_b-1 |
| 116 | `605046006a` | Azuria: Beerenpuder-Mann prüft Beeren im Beutel statt Beerentüte | T-kanto_a-6, W-progress_sim-15 |
| 117 | `e29aa5d3f2` | Vertania: Tutorial-Opa fragt nicht mehr nach dem Lehrkanal | T-kanto_a-5 |
| 118 | `15b545ea9a` | Alabastia: Sarahs Abschiedstext nach dem Pokédex nicht noch einmal | T-kanto_a-7 |
| 119 | `6518eabf61` | Fuchsania-Zoo: Fossil-Schild zeigt immer Amonitas wie das Gehege | T-kanto_b-4 |
| 120 | `ffbdea3d0d` | Magnetzug: Spieler steht nach der Ankunft nicht im Schaffner | T-kanto_b-6 |
| 121 | `08e3149815` | Azuria: Beerenpuder-Tauschtext passt mit langen Itemnamen in die Box | T-kanto_a-6, W-text_width-3 |

#### `w3b`: Hall of Fame and clock

| # | Commit | Title | Findings |
|---:|---|---|---|
| 122 | `cd155adc3d` | Ruhmeshalle: Johto, Hoenn und PC-Anzeige fassen 50 Teams wie Kanto | A121, W-core_save-1 |
| 123 | `5e1b5f870d` | Neues Spiel: Fake-Uhr vorgewählt, wenn die Modul-Uhr nicht läuft | A35, W-core_save-2 |

#### `text_width`: `tools/check_game_text.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 124 | `a81e0f6dad` | Werkzeug: Spieltexte im Quelltext messen und englische Reste finden | - |
| 125 | `e847161c54` | Werkzeug: Textprüfung bewertet Debug- und Sinjoh-Texte nach ihrer Karte | - |
| 126 | `b887df3606` | Werkzeug: Textprüfung meldet englische Trainernamen der .party-Dateien | - |

#### `core_save`: `tools/check_save_safety.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 127 | `9ea6ff6d2d` | Werkzeug: statische Prüfung von Geschenken, Taschen und neuem Spiel | - |
| 128 | `46be3a9de6` | Speicherprüfung: Ruhmeshalle, RTC und Link-Funktionen | - |

#### `progress_sim`: `tools/oj_world.py`, `tools/simulate_progress.py`

| # | Commit | Title | Findings |
|---:|---|---|---|
| 129 | `8dede143ee` | Werkzeuge: gemeinsame Datenschicht oj_world.py für statische Prüfungen | - |
| 130 | `c415155a59` | Werkzeuge: Durchspiel-Simulator simulate_progress.py | - |

#### `w3_johto`: Johto

| # | Commit | Title | Findings |
|---:|---|---|---|
| 131 | `63f7024435` | Steineichenwald: Holzkohlemeister setzt Azalea nicht mehr zurück | T-johto_a-1 |
| 132 | `7e3c346926` | Neuborkia: fremdes Haus holt das Route-30-Duell nicht mehr zurück | T-johto_a-3 |
| 133 | `896c802fac` | Sandra-Arena: kein zweiter Kampf nach dem Drachenschrein | T-johto_b-1 |
| 134 | `9df1dfe85a` | Kimono-Girl Zuki: Text ohne Fang sagt nicht mehr „eingefangen“ | T-legend_endgame-1 |
| 135 | `ffe4fc5792` | Lugia und Ho-Oh: kein „flog davon!“ nach einem K.O. | T-legend_endgame-4 |
| 136 | `b702b50666` | Kimono-Tanz: läuft pro Besuch nur einmal | T-johto_b-5 |
| 137 | `ac408421ec` | Steineichenwald: Niederlage gegen Celebi lässt keine Figuren zurück | T-legend_endgame-2 |
| 138 | `bf713b3067` | Kampfzone: Mogelbaum steht auf einem erreichbaren Feld | A65, W-map_checker-10, W-progress_sim-9 |
| 139 | `e30f4f495e` | Lind erkennt das geschlüpfte Ei aus Viola City auch mit Randomizer | A122, T-johto_a-5 |

#### `w3_nuzlocke`: Nuzlocke nicknames and D-039

| # | Commit | Title | Findings |
|---:|---|---|---|
| 140 | `de88177172` | Nuzlocke: Spitznamenpflicht auch für den Kanto-Starter | A87, T-kanto_a-12 |
| 141 | `2077bf9dbe` | Nuzlocke: Johto-Starter im PC bekommt auch einen Spitznamen | A87, T-johto_a-4 |
| 142 | `551f9a1327` | Nuzlocke: Spitznamenpflicht für weitere Johto-Geschenke | A87 |
| 143 | `ed568069c4` | Nuzlocke: Spitznamenpflicht auch für Hoenns Geschenk-Pokémon | A87, T-hoenn_a-10 |
| 144 | `b62f22e381` | DECISIONS: D-039 ohne Wanderer auf Route 26 | T-legend_endgame-5 |

### Documentation

| # | Commit | Title | Findings |
|---:|---|---|---|
| 145 | `38a08f72f4` | Doku: Budgetzahlen in D-017 auf den aktuellen Stand | A38 |
| 146 | `bb1681f692` | Doku: CHANGELOG.md für Spieler und Tester dieser Runde | - |
| 147 | this commit | Doku: PATCHES.md mit Reihenfolge, Prüfung und Anwendung der Reihe | - |
| 148 | follows | Doku: BETA_READINESS.md mit Kriterien, offenen Punkten und Risiken | - |
| 149 | follows | Doku: TESTS.md um die Prüfwerkzeuge und die Testmatrix ergänzt | A10 |
| 150 | follows | Doku: README.md für Origin Jade | A46 |

The ids of commits 147 to 150 are in `git log`; a commit cannot name its
own id. `src/data/debug_kanto_complete.h` was up to date, so no commit
regenerates it.
