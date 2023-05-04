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
add_compile_definitions(OS_${OS_NAME})

add_subdirectory(utils)
add_subdirectory(window)

add_executable(kitsunengine main.cpp)

target_include_directories(kitsunengine PRIVATE window/include utils/include)
target_link_libraries(kitsunengine PRIVATE kitsunengine-window kitsunengine-utils)