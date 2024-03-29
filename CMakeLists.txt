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

option(USE_IMGUI "Enable ImGui" TRUE)

# C++ Settings

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Internal CMake Options

if(WIN32)
    set(EXE_TYPE WIN32)
endif(WIN32)
if(WIN32 OR UNIX)
    set(PLATTFORM_DESKTOP TRUE)
    set(PLATTFORM "desktop")

    set(INCLUDE_HEADERS
        firstparty/libkitsune/include()
        thirdparty/sdl/include 
        thirdparty/glad/include 
        thirdparty/sdl_mixer/include 
        thirdparty/sdl_image/include 
        include
    )

    set(LIBRARIES
        libkitsune
        glad 
        SDL2
        SDL2_mixer 
        SDL2_image
    )

    if(USE_IMGUI)
        list(APPEND INCLUDE_HEADERS thirdparty/imgui)
        list(APPEND LIBRARIES imgui)
    endif()
endif()
if(NINTENDODS OR NINTENDO3DS)
    set(PLATTFORM_DS TRUE)
    if(NINTENDODS)
        set(PLATTFORM "ds")
    else()
        set(PLATTFORM "3ds")
    endif()
endif()

# Main Library

string(TOLOWER lib${PROJECT_NAME} LIB_NAME)

file(GLOB_RECURSE ${LIB_NAME}_HEADERS include/*.hpp)

add_library(${LIB_NAME}
    ${${LIB_NAME}_HEADERS}

    source/app.cpp
    source/app_${PLATTFORM}.cpp
    
    source/utils/sdl.cpp
    source/utils/opengl.cpp

    source/core/display_${PLATTFORM}.cpp
    source/core/context.cpp
    source/core/context_${PLATTFORM}.cpp
)

# Main Library Settings

add_subdirectory(firstparty)
if(PLATTFORM_DESKTOP)
    # 3rd-Party
    add_subdirectory(thirdparty)
    target_compile_definitions(${LIB_NAME} PRIVATE PLATTFORM_DESKTOP)

    target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_HEADERS})
    target_link_libraries(${LIB_NAME} PRIVATE ${LIBRARIES})
    if(USE_IMGUI)
        target_compile_definitions(${LIB_NAME} PRIVATE USE_IMGUI)
    endif()
endif()

if(PLATTFORM_DS)
    target_compile_definitions(${LIB_NAME} PRIVATE PLATTFORM_DS)
endif()

# Main Executable

add_executable(${PROJECT_NAME} ${EXE_TYPE} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME} ${LIBRARIES} SDL2main)

message(STATUS "Plattform: ${PLATTFORM}")
message(STATUS "Use ImGui: ${USE_IMGUI}")