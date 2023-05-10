file(GLOB_RECURSE AUDIO_SOURCES source/*.cpp)

add_library(kitsunengine-audio STATIC ${AUDIO_SOURCES})

target_include_directories(kitsunengine-audio PRIVATE include)

target_include_directories(kitsunengine-audio PRIVATE ${PROJECT_SOURCE_DIR}/utils/include)
target_link_libraries(kitsunengine-audio PRIVATE kitsunengine-utils)