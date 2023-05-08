if(WIN32)
    add_library(kitsunengine-window STATIC win32.cpp)
endif(WIN32)

target_include_directories(kitsunengine-window PRIVATE include)

target_link_libraries(kitsunengine-window PRIVATE kitsunengine-utils kitsunengine-input)
target_include_directories(kitsunengine-window PRIVATE ${PROJECT_SOURCE_DIR}/utils/include ${PROJECT_SOURCE_DIR}/input/include)