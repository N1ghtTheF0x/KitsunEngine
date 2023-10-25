cmake_minimum_required(VERSION 3.22)

project(KitsunEngine)

# General CMake Settings

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/lib )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/lib )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

# CMake Options

option(USE_IMGUI "Enable ImGui")

# C++ Settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main Library

string(TOLOWER lib${PROJECT_NAME} LIB_NAME)

add_library(${LIB_NAME}
    source/app.cpp

    source/utils/string.cpp
)

# Internal CMake Options

if(WIN32 OR UNIX)
    set(PLATTFORM_DESKTOP TRUE)
    target_compile_definitions(${LIB_NAME} PRIVATE PLATTFORM_DESKTOP)
endif()
if(NINTENDODS OR NINTENDO3DS)
    set(PLATTFORM_DS TRUE)
    target_compile_definitions(${LIB_NAME} PRIVATE PLATTFORM_DS)
endif()

# Main Library Settings

if(PLATTFORM_DESKTOP)
    # 3rd-Party
    add_subdirectory(thirdparty)

    target_include_directories(${LIB_NAME} PUBLIC include thirdparty/glad/include thirdparty/sdl/include)
    target_link_libraries(${LIB_NAME} PRIVATE glad SDL2)
    if(USE_IMGUI)
        target_include_directories(${LIB_NAME} PUBLIC thirdparty/imgui)
        target_link_libraries(${LIB_NAME} PRIVATE imgui)
    endif()
endif()

# Main Executable

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME})