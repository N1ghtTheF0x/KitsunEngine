file(GLOB_RECURSE UTILS_SOURCES source/*.cpp)

add_library(kitsunengine-utils STATIC ${UTILS_SOURCES})

target_include_directories(kitsunengine-utils PRIVATE include ../other/lua ../other/sol2/include)
target_link_libraries(kitsunengine-utils PRIVATE lua::lua sol2::sol2)