cmake_minimum_required(VERSION 3.14)
project(swarm-sim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 20)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)

set(PROJECT_NAME simulator.app)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.0.0
    )
    FetchContent_MakeAvailable(raylib)
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

# GLM
find_package(glm REQUIRED)
if (NOT glm_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 0.9.9.8
    )
    FetchContent_MakeAvailable(glm)
endif()


#spdLog
set(CMAKE_THREAD_LIBS_INIT "-lpthread")

find_package(spdlog)
if (NOT spdlog_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.10.0
    )
    FetchContent_MakeAvailable(spdlog)
endif()

# imgui
add_subdirectory(include/imgui_glfw_opengl3_impl)

# Project sources
include_directories("${CMAKE_CURRENT_SOURCE_DIR}") # Sets include paths
set(SOURCES main.cpp
    src/application/Application.h src/application/Application.cpp

    src/core/Log.h src/core/Log.cpp

    src/sim/Robot.h src/sim/Robot.cpp
    src/sim/Simulator.h src/sim/Simulator.cpp
    src/sim/SimulatorState.h src/sim/SimulatorState.cpp

    src/ui/PropertyPanel.h src/ui/PropertyPanel.cpp
    src/ui/SimulatorView.h src/ui/SimulatorView.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})

# libs
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_link_libraries(${PROJECT_NAME} PUBLIC
        raylib
        raylib_cpp
        imgui
        spdlog::spdlog
        )

# set(PLATORM "DESKTOP")

# # Web Configurations TODO make this work!
# if (${PLATFORM} STREQUAL "Web")
#     # Tell Emscripten to build an example.html file.
#     set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
# endif()
