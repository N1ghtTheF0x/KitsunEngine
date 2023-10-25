![KitsunEngine Logo][kitsunengine-logo]

# KitsunEngine

A game engine made by me :D

# Setup

The best way is just to use Visual Studio Code with the C++ Extensions and CMake Extensions. I don't even know if the instructions below work ._.

1. clone this repo and enter this in your console/terminal
```shell
git submodule update --init --recursive
```
2. After you came back from the toilet, you make do the CMake stuff:
```shell
mkdir build
cd build
# You can use "cmake --list-presets" or just look into the "CMakePresets.json" file to see every option
cmake --preset=<the-preset-name> .. 
```
3. Now you can build a build:
```shell
cmake --build ..
```
4. ???
5. profit


# 3th-Party License Stuff

[SDL2][sdl2-link], [SDL2_image][sdl2_image-link] and [SDL2_mixer-link][sdl2_mixer-link] are all licensed to `zlib License`

# License

This project is licensed under [this][license-link] license

[sdl2-link]: https://github.com/libsdl-org/SDL
[sdl2_image-link]: https://github.com/libsdl-org/SDL_image
[sdl2_mixer-link]: https://github.com/libsdl-org/SDL_mixer

[kitsunengine-logo]: ./brand/logo.png
[license-link]: ./LICENSE