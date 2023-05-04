file(GLOB_RECURSE UTILS_SOURCES source/*.cpp)

add_library(kitsunengine-utils STATIC ${UTILS_SOURCES})

target_include_directories(kitsunengine-utils PRIVATE include)