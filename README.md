# Micah's Village

An open-source 2D colony game in the style of RollerCoaster Tycoon that serves as a learning project and a dream game that I'd like to play.

## Goals

I want a highly optimised game (or engine) capable of simulating a gargantuan number of NPCs, with millions of in-game world items, while keeping the charm of those classic 90's RTS and civ-building games.

## Architecture

Considering the scope of the game/engine, a data-oriented approach is mandatory. We need to squeeze every ounce of performance we can get.

## Project Structure

```text
micahsvillage/
├── assets/          # Game assets (e.g., human_sprite.png)
├── Libraries/       # Third-party dependencies
├── build/           # Build output
└── workspace/       # Source files
    ├── src/         # Source code (.cpp)
    └── include/     # Header files (.h)
```

## Acknowledgements

```text
Raylib — a simple and easy-to-use library for enjoying video game programming, developed by Ramon Santamaria (raysan5).

KalaMake — the build system used by this project, developed by Lost Empire Entertainment.
A very big thanks for making a great alternative to CMake, which has really saved me time and loads of headaches.

Lost Empire Entertainment — if you want to explore their broader ecosystem of tools and engines, check out their GitHub.
Note: Their Elypso Engine is currently being reworked.
```
