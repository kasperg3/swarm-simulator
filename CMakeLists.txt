cmake_minimum_required(VERSION 3.14)
project(swarm-sim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)

set(PROJECT_NAME simulator.app)

# raylib
find_package(raylib 4.0.0 QUIET CONFIG)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG GIT_TAG 4.0.0
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()


# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.2.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# imgui
add_subdirectory(vendor/imgui_glfw_opengl3_impl)

# Project sources
set(SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

# libs
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_link_libraries(${PROJECT_NAME}
        raylib
        raylib_cpp
        imgui
        )

target_link_libraries(${PROJECT_NAME} imgui)

# Web Configurations TODO make this work!
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()
