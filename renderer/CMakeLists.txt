file(GLOB_RECURSE RENDERER_SOURCES source/*.cpp)

find_package(OpenGL REQUIRED)

if(NOT OPENGL_GLU_FOUND)
    message(FATAL_ERROR "No GLU!")
endif(NOT OPENGL_GLU_FOUND)

add_library(kitsunengine-renderer STATIC ${RENDERER_SOURCES})

target_include_directories(kitsunengine-renderer PRIVATE include)

target_link_libraries(kitsunengine-renderer PRIVATE ${OPENGL_LIBRARIES} PRIVATE kitsunengine-utils)
target_include_directories(kitsunengine-renderer PRIVATE ${OPENGL_INCLUDE_DIR} PRIVATE ../utils/include)