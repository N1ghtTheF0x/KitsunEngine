# SDL2
set(SDL2_DISABLE_INSTALL ON)
set(SDL2_DISABLE_UNINSTALL ON)
set(SDL_TESTS OFF)
set(SDL_INSTALL_TESTS OFF)
add_subdirectory(sdl)
set(SDL2MIXER_SAMPLES OFF)
set(SDL2MIXER_INSTALL OFF)
add_subdirectory(sdl_mixer)
set(SDL2IMAGE_SAMPLES OFF)
set(SDL2IMAGE_TESTS OFF)
add_subdirectory(sdl_image)
# ImGui
if(USE_IMGUI)
    add_subdirectory(imgui)
endif(USE_IMGUI)
# Glad
add_subdirectory(glad)