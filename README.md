![Banner Image](/banner.png)

<p align="center">
  <img src="https://github.com/OGNylux/cpp-gameactions/workflows/ci.yml/badge.svg" />
  <img src="https://badgen.net/github/release/OGNylux/cpp-game" />
</p>

## Just Another Platformer

'Just Another Platformer' is a game that just as the name suggests, follows the platformer game genre. You play as an adventurer.
You can walk around the level, jump on higher platforms, collect hearts to replenish your health and slay enemies with your sword.
Slay all enemies to... nothing, there's no game-loop. You can walk around afterwards though.

## How to play
Extract the `windows_x64.zip` file and run the `platformer.exe` executable.\
- Navigate the menus by clicking the buttons with the mouse
- Move the player with the right and left arrow keys
- Sprint with with the ctrl key
- Jump with the up arrow key
- Swing your sword with the space key

## Build

### Prerequisites

- CMake 3.16 or later

### Used Libraries

- SFML v2.6.1 (https://github.com/SFML/SFML)
- box2d v2.4.1 (https://github.com/erincatto/box2d)

### Windows

Make sure to have Visual Studio (e.g. 2022 Community) installed with the C++ development tools. Then run the following
commands in the command prompt:

```bash
cmake -G "Visual Studio 17 2022" -A x64 -S . -B "build64" #64-bit build
cmake --build build64 --config Release
cd build64/bin7
mv .\assets\ .\Release\
```
The game can be run by executing the `platformer.exe` executable in the `build64/bin/Release` directory.

## Development

The project was developed as part of the 'Programmieren in C++' module at the Berlin School of Economics and Law (HWR
Berlin).\
Therefore this game is developed in C++ using the libraries SFML2 for graphics and input handling and box2d for world and physics handling.
As soon as the application starts, the Game class is initialized. This also initializes the `Physics` class, the Player and all other objects (e.g. enemies and hearts) in the `Map` class.
The createFromImage method in the `Map` class uses a static image to get a grid of all object positions.
After the game is initialized the application loops the update, render and renderUI methods as long as the application is running.
The update method _updates_ the physics, camera position, player and all other objects.
The render method _renders_ the background, tiles, player and all other objects.
And the renderUI method _renders_ the hearts and individual user interfaces.

When an entity (e.g. player or enemy) is initialized all animations and hitboxes are initialized as well.
The update method of an entity ensures that the entity can actually move and the right animation is played at the right time. 
This means that the player input is handled in this update method.

If an object gets collected or killed the corresponding deconstructor flags its physics-body for removal and is removed in the next game-tick.

## Known Issues

- Hearts give you more than one health points sometimes (the hitboxes are not very good)
- There's no real game-loop

## Credits

- Background (https://craftpix.net/freebies/free-sky-with-clouds-background-pixel-art-set/)
- Adventurer (https://rvros.itch.io/animated-pixel-hero)
- Hearts (https://temok.itch.io/heart-container-animated-in-pixel-art)
- Slime (https://rvros.itch.io/pixel-art-animated-slime)
- Tiles (https://trixelized.itch.io/starstring-fields)