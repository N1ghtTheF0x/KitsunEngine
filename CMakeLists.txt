cmake_minimum_required(VERSION 3.22)

project(KitsunEngine)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_compile_definitions(X64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    add_compile_definitions(X32)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_SOURCE_DIR}/lib )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_SOURCE_DIR}/lib )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_SOURCE_DIR}/bin )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Operating System: ${CMAKE_SYSTEM_NAME}")

string(TOUPPER ${CMAKE_SYSTEM_NAME} OS_NAME)
add_compile_definitions(OS_${OS_NAME} OS_NAME="${CMAKE_SYSTEM_NAME}")

if(UNIX)
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    include_directories(${X11_INCLUDE_DIR})
endif(UNIX)

find_package(Threads REQUIRED)
link_libraries(Threads::Threads)

set(ALSOFT_EXAMPLES OFF)
set(ALSOFT_UTILS OFF)
add_subdirectory(media/openal)
add_subdirectory(utils)

link_libraries(kitsunengine-utils)
include_directories(utils/include)

add_subdirectory(input)
add_subdirectory(window)
add_subdirectory(renderer)
add_subdirectory(media)

if(WIN32)
    set(SETUP_WINDOWS WIN32)
endif(WIN32)

add_executable(kitsunengine ${SETUP_WINDOWS} main.cpp)

target_include_directories(kitsunengine PRIVATE window/include utils/include input/include renderer/include media/include)
target_link_libraries(kitsunengine PRIVATE kitsunengine-window kitsunengine-utils kitsunengine-input kitsunengine-renderer kitsunengine-media)