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

# Internal CMake Options

if(WIN32)
    set(EXE_TYPE WIN32)
endif(WIN32)
if(WIN32 OR UNIX)
    set(PLATTFORM_DESKTOP TRUE)
    set(PLATTFORM_CPP "desktop")

    

    set(INCLUDE_HEADERS
        thirdparty/sdl/include 
        thirdparty/glad/include 
        thirdparty/sdl_mixer/include 
        thirdparty/sdl_image/include 
        include
    )

    set(LIBRARIES
        glad 
        SDL2 
        SDL2main
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
        set(PLATTFORM_CPP "ds")
    else()
        set(PLATTFORM_CPP "3ds")
    endif()
endif()

# C++ Settings

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main Library

string(TOLOWER lib${PROJECT_NAME} LIB_NAME)

file(GLOB_RECURSE ${LIB_NAME}_HEADERS include/*.hpp)

add_library(${LIB_NAME}
    ${${LIB_NAME}_HEADERS}

    source/app.cpp
    source/app_${PLATTFORM_CPP}.cpp

    source/utils/string.cpp
    source/utils/logger.cpp
    source/utils/date.cpp
    
    source/core/display_${PLATTFORM_CPP}.cpp
)

# Main Library Settings

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
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME} ${LIBRARIES})