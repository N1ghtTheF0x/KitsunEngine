if(WIN32)
    set(OS_SOURCE win32.cpp)
endif(WIN32)

if(UNIX)
    set(OS_SOURCE linux.cpp)
endif(UNIX)

add_library(kitsunengine-window STATIC window.cpp ${OS_SOURCE})

target_include_directories(kitsunengine-window PRIVATE include)

target_link_libraries(kitsunengine-window PRIVATE kitsunengine-utils kitsunengine-input)
target_include_directories(kitsunengine-window PRIVATE ${PROJECT_SOURCE_DIR}/utils/include ${PROJECT_SOURCE_DIR}/input/include)