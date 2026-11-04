# Entwickler-Hinweise

## Bauen

Benötigt: `gcc-arm-none-eabi`, `binutils-arm-none-eabi`, `libnewlib-arm-none-eabi`, `libpng-dev`, Python 3.

    make -j$(nproc)    # Pokemon_Origin_Jade.gba, Beta-Build mit Debug-Menü
    make release       # Pokemon_Origin_Jade-release.gba, ohne Debug-Menü

Es wird nur Origin Jade gebaut (`IS_HNS`, Kartenversion `hns`).

## Prüfwerkzeuge

Aufruf mit `python3 -I tools/<name>`:

| Werkzeug | Prüft |
|---|---|
| `check_flags.py` | Jedes Flag und jede Var hat Speicherplatz, keine Doppelbelegung; `--free` zeigt freie Nummern. Vor jedem Commit. |
| `make_debug_states.py --check` | Die Debug-Spielstände „Johto Test“ und „Hoenn Test“ passen zum Code; ohne `--check` neu erzeugen. |
| `check_save_safety.py`, `check_budget.py` | Spielstand-Sicherheit und Speicherplatz (SaveBlocks, EWRAM, IWRAM, ROM). |
| `check_text_width.py --list` | Textzeilen über 208 px. |
| `check_game_text.py --english` | Englischer Text, den das Spiel zeigen kann. |
| `check_maps.py` | Kartenfehler (Warps, Objekte, Items, Wege). |
| `simulate_progress.py` | Erreichbarkeit: alle drei Titel, unerreichbare Karten und Items. |
| `check_regions.py` | Arten je Region (Wildtabellen, Pokédex-Reihenfolge). |

## Regeln

- **Spielstand:** Ab dem Beta-Release gilt der Save-Freeze: keine neuen oder verschobenen Flags, Vars, Karten, Heilorte oder SaveBlock-Felder ohne Absprache. Neue Flags kommen nur auf freie Nummern (`check_flags.py --free`).
- **Texte:** Deutsch im offiziellen Wortlaut (Poké-Corpus), jede Zeile höchstens 208 px. Die englischen `#else`-Zweige bleiben. Code-Kommentare kurz auf Englisch.
- **Karten:** Bearbeitung in Porymap. Stillgelegte Karten (`game_version` mit `_retired`: Sevii-Inseln, Smaragd-Kampfzone, Kampfzelte, Smaragd-Trainerberg) bleiben im Repo, weil der Code sie braucht. Sinjoh und Alola sind gesperrt.
- **Commits:** klein und auf Deutsch.

Die alte Doku (Entscheidungslog, Audit, Testsuite) liegt auf dem Branch `alt`.
