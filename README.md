# KitsunEngine

A Game Engine made from scratch

## Cross-Plattform

OpenAL is used for audio playback. OpenAl is licensed under the [LGPL v2 License][openal-license]
Lua with Sol3 is used for scripting. Lua is licensed under the [MIT License][lua-license] and Sol3 is licensed under the [MIT License][sol3-license]

## Windows

Windows uses the `win32`-API for the window
Used [this][win32-guide] as a starting point

## Linux

Linux uses the `X11` Library for the window. `X11` is licensed under the [MIT License][x11-license]
Used [this][khronos-opengl-guide] and [this][x11-guide] as a starting point

## MacOS

Sorry guys, but I'm gonna be the same asshole like Apple. (No Mac? No Support! Fair and square!)

[openal-license]: https://raw.githubusercontent.com/kcat/openal-soft/master/COPYING
[sol3-license]: https://raw.githubusercontent.com/ThePhD/sol2/develop/LICENSE.txt
[lua-license]: https://www.lua.org/license.html

[x11-guide]: http://mech.math.msu.su/~vvb/2course/Borisenko/CppProjects/GWindow/xintro.html
[x11-license]: https://raw.githubusercontent.com/mirror/libX11/master/COPYING

[khronos-opengl-guide]: https://www.khronos.org/opengl/wiki/Programming_OpenGL_in_Linux:_GLX_and_Xlib

[win32-guide]: https://learn.microsoft.com/en-us/windows/win32/learnwin32/your-first-windows-program