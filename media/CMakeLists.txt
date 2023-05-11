file(GLOB_RECURSE MEDIA_SOURCES source/*.cpp)

add_library(kitsunengine-media STATIC ${MEDIA_SOURCES})

target_include_directories(kitsunengine-media PRIVATE include)

target_include_directories(kitsunengine-media PRIVATE ${PROJECT_SOURCE_DIR}/utils/include)
target_link_libraries(kitsunengine-media PRIVATE kitsunengine-utils)