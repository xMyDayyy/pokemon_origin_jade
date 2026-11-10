# Development notes

## Building

Needs `gcc-arm-none-eabi`, `binutils-arm-none-eabi`, `libnewlib-arm-none-eabi`, `libpng-dev` and Python 3.

    make -j$(nproc)    # Pokemon_Origin_Jade.gba, beta build with debug menus
    make release       # Pokemon_Origin_Jade-release.gba, without debug menus

Only Origin Jade is built (`IS_HNS`, map version `hns`).

The title screen shows the version below PRESS START in every build; it is drawn in `graphics/title_screen/origin_jade/press_start.png`. The beta build stops with a crash screen when a flag or var without save space is used (START continues); `make release` does not.

## Beta patch

1. Set the version digits in `graphics/title_screen/origin_jade/press_start.png` (9x7 px per digit, right-aligned at x=124) and build with `make` (the beta is the build with debug menus).
2. Create the patch with Floating IPS against a clean Pokémon Emerald (USA/Europe), SHA-1 `f3ae088181bf583e55daf962a92bb46f4f1d07b7`:
   `flips --create --bps <clean Emerald .gba> Pokemon_Origin_Jade.gba OriginJade_Beta1.bps`
3. Take the SHA-1 of the patched ROM: `sha1sum Pokemon_Origin_Jade.gba`.
4. Publish a GitHub release on `master` with the `.bps` file and that SHA-1 in the notes.
5. Never upload ROM files, neither the clean nor the patched one.

## Check tools

Run with `python3 -I tools/<name>`:

| Tool | Checks |
|---|---|
| `check_flags.py` | Every flag and var has save space, no double use; `--free` lists free ids. Run before every commit. |
| `make_debug_states.py --check` | The debug saves "Johto Test" and "Hoenn Test" match the code; without `--check` it regenerates them. |
| `check_save_safety.py`, `check_budget.py` | Save safety and memory budget (save blocks, EWRAM, IWRAM, ROM). |
| `check_text_width.py --list` | Text lines wider than 208 px. |
| `check_game_text.py --english` | English text the game can show. |
| `check_maps.py` | Map errors (warps, objects, items, paths). |
| `simulate_progress.py` | Progression: all three titles, unreachable maps and items. |
| `check_regions.py` | Species per region (wild tables, Pokédex order). |

## Rules

- **Saves:** from the beta release on, the save layout is frozen: no new or moved flags, vars, maps, heal locations or save block fields without agreement. New flags only go to free ids (`check_flags.py --free`).
- **Texts:** German in the official wording (Poké-Corpus), every line at most 208 px. The English `#else` branches stay. Code comments are short and in English.
- **Maps:** edit in Porymap. Retired maps (`game_version` ending in `_retired`: Sevii Islands, Emerald Battle Frontier, Battle Tents, Emerald Trainer Hill) stay in the repo because the code needs them. Sinjoh and Alola are locked. Emerald-tileset maps (Hoenn, the Trainer Hill buildings) are edited with the `…_EMERALD` primary tile counts in Porymap's project settings; save each map only in its own mode.
- **Commits:** small.

The old documentation (design log, audit, test suite) is on the branch `alt`.
