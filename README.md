# Pokémon Origin Jade

![Pokémon Origin Jade](logo.png)

Pokémon Origin Jade is a ROM hack for the Game Boy Advance: one journey
through three regions, Kanto first, then Johto, then Hoenn. Kanto uses the
FireRed/LeafGreen maps, Johto comes from Pokémon Heart & Soul 2.0.5, Hoenn
from Emerald. It is built on pokemonHnS-expansion (Heart & Soul) and RHH's
pokeemerald-expansion.

The game is in German for now; an English version is planned during the
beta.

## Features

- **Three regions in a row**, each with its own badges, league and title.
  Field moves follow the region's rules (Kanto badges, Johto permits,
  Hoenn licenses). The credits roll at the end of the whole journey.
- **Kanto in the FireRed/LeafGreen style**, with a hand-set level curve up
  to the champion.
- **Level scaling in Johto and Hoenn**: trainers and wild Pokémon follow
  your team within level corridors per area.
- **Region rule**: Pokémon of a region show up once the story reaches it.
- **Troy's story**: after the Johto title Troy brings the Hoenn Ticket.
- **Contests as in Ruby and Sapphire**, one rank per contest hall.
- **Battle Frontier and Trainer Hill** from Heart & Soul.
- **No trading needed**: every species and every item can be obtained in
  one game.
- **Challenges** for a new game: Nuzlocke, randomizer, level caps and more.

## Playing

Apply the BPS patch to a clean Pokémon Emerald ROM (USA/Europe,
SHA-1 `f3ae088181bf583e55daf962a92bb46f4f1d07b7`), for example with
[Rom Patcher JS](https://www.marcrobledo.com/RomPatcher.js/) or Floating
IPS. Patches are published with each beta release.

The beta is still in progress: saves may not carry over between beta
versions. Trades and link battles come from Heart & Soul and were not
tested; linking with the official games or other ROM hacks is not
supported.

## Building

Install `gcc-arm-none-eabi`, `binutils-arm-none-eabi`,
`libnewlib-arm-none-eabi`, `libpng-dev` and Python 3, then:

    make -j$(nproc)    # Pokemon_Origin_Jade.gba (beta build, debug menus on)
    make release       # Pokemon_Origin_Jade-release.gba (debug menus off)

Check tools and rules for changes: [`DEVELOPMENT.md`](DEVELOPMENT.md).

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
