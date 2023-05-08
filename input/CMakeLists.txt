file(GLOB_RECURSE INPUT_SOURCES source/*.cpp)

add_library(kitsunengine-input STATIC ${INPUT_SOURCES})

target_include_directories(kitsunengine-input PRIVATE include)

target_include_directories(kitsunengine-input PRIVATE ${PROJECT_SOURCE_DIR}/utils/include)
target_link_libraries(kitsunengine-input PRIVATE kitsunengine-utils)