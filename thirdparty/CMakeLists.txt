# SDL2
set(SDL2_DISABLE_INSTALL OFF)
set(SDL2_DISABLE_UNINSTALL OFF)
set(SDL_TESTS OFF)
set(SDL_INSTALL_TESTS OFF)
add_subdirectory(sdl)
# ImGui
add_subdirectory(imgui)
# Glad
add_subdirectory(glad)