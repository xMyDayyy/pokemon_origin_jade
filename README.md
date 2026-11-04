# Pokémon Origin Jade

Pokémon Origin Jade is a German ROM hack for the Game Boy Advance: one
journey through three regions, Kanto first, then Johto, then Hoenn. Kanto
uses the FireRed/LeafGreen maps, Johto comes from Pokémon Heart & Soul
2.0.5, Hoenn from Emerald. The game is built on pokemonHnS-expansion
(Heart & Soul) and RHH's pokeemerald-expansion.

The game text is German. Code comments and the project documentation are
English.

## Features

- **Three regions in order.** The game starts in Pallet Town; Kanto is
  chapter one, then Johto and Hoenn, each with its own badges, league and
  title. Field moves follow the region's rules (Kanto badges, Johto
  permits, Hoenn licenses). The credits come at the end of the whole
  journey.
- **Level design.** Kanto has a hand-set level ladder up to the champion
  at 45-47. Johto and Hoenn scale trainers and wild Pokémon to the
  player's team, within level corridors per area.
- **No trading needed.** Kanto and Hoenn are designed so that their
  Pokédex can be completed without trading; all nine starters are also
  wild.
- **Contests as in Ruby and Sapphire.** One rank per contest hall:
  Verdanturf Town (Normal, with the Contest Pass), Fallarbor Town
  (Super), Slateport City (Hyper) and Lilycove City (Master). The endgame
  facilities are Heart & Soul's: its Battle Frontier (Kampfzone) and the
  Trainer Hill by Route 40.
- **Challenges**, chosen in the challenge menu of a new game: Nuzlocke
  (with nickname rule and hardcore mode), randomizer (starters, wild,
  fixed and trainer Pokémon, evolutions, moves, items), level caps, item
  prices, fewer escapes, EXP multiplier, no EVs, maximum IVs, no Pokémon
  Center, one-type challenge, clock type.
- **Debug menus in beta builds.** The overworld debug menu (R + Start) and
  the battle debug menu (Select) are on in the build made by `make` and
  off in `make release`.

## Building

Install `gcc-arm-none-eabi`, `binutils-arm-none-eabi`,
`libnewlib-arm-none-eabi`, `libpng-dev` and Python 3, then:

    make -j$(nproc)              # Pokemon_Origin_Jade.gba (beta build, debug menus on)
    make release                 # Pokemon_Origin_Jade-release.gba (debug menus off)

`make` builds only Origin Jade; `make jade` is an alias. Check tools and
rules for changes: [`ENTWICKLER.md`](ENTWICKLER.md) (German).

## Current state

Beta preparation. Kanto, Johto and Hoenn can be played to their titles
without a known blocker: after the first Johto title Troy hands over the
Hoenn Ticket in Prof. Oak's lab. This is checked statically and with the
check tools, not yet in an emulator. Every text the German build shows
on the story path is German; English is left only in debug texts, in
unused texts and in trainer names that no active script shows; some of
the new German texts are still drafts.

Until the release the save layout may still change, and older saves are
not migrated.

Trades and link battles come from Heart & Soul and were not tested in
Origin Jade. Linking with the official games or other ROM hacks is not
supported.

## Credits

Origin Jade stands on a chain of projects. If you use it, credit Origin
Jade and keep the full chain:

- **Pokémon Heart & Soul** (pokemonHnS-expansion) 2.0.5 by the HnS team,
  [PokemonHnS-Development/pokehns-expansion](https://github.com/PokemonHnS-Development/pokehns-expansion).
  Its contributors are listed in [`CREDITS.md`](CREDITS.md).
- **Modern Emerald** by resetes12,
  [resetes12/pokeemerald](https://github.com/resetes12/pokeemerald), the
  base Heart & Soul was first built on.
- **pokeemerald-expansion** by RHH (Rom Hacking Hideout),
  [rh-hideout/pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion),
  version 1.15.1 with later unreleased changes
  (`include/constants/expansion.h`) and selected fixes up to 1.17.1.
- **pokeemerald** by pret,
  [pret/pokeemerald](https://github.com/pret/pokeemerald), the
  decompilation all of these build on.

Heart & Soul asks everyone who uses it to credit Pokémon Heart and Soul,
to retain the full chain of credits, and, with a more recent
pokeemerald-expansion, to credit RHH with the version number. For example:

```
Pokémon Origin Jade is based on Pokémon Heart & Soul 2.0.5
(pokemonHnS-expansion), built on resetes12's Modern Emerald and RHH's
pokeemerald-expansion 1.15.1, which build on pret's pokeemerald.
```

Please also consider crediting all contributors listed in
[`CREDITS.md`](CREDITS.md).
