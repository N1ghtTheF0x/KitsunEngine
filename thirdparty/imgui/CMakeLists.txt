project(ImGui)
add_library(imgui STATIC
    imconfig.h
    imgui_internal.h
    imgui.h
    imgui.cpp
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    imgui_impl_sdl2.cpp
    imgui_impl_sdl2.h
    imgui_impl_opengl3_loader.h
    imgui_impl_opengl3.cpp
    imgui_impl_opengl3.h
)
target_link_libraries(imgui PRIVATE SDL2)
target_include_directories(imgui PRIVATE ${SDL2_SOURCE_DIR}/include)