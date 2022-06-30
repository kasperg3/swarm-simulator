cmake_minimum_required( VERSION 3.12...3.13 )

project( SwarmSim
         VERSION 1.0.0
         DESCRIPTION "Simple multi robot simulator" )


# Libraries 
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

# GLM
find_package(glm QUIET)
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
add_subdirectory(external/imgui_glfw_opengl3_impl)

# Create a shared library
add_library(${PROJECT_NAME} OBJECT)

target_sources(${PROJECT_NAME} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/application/SwarmSimulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/Log.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sim/Robot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sim/Boids.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sim/Simulator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sim/SimulatorState.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/PropertyPanel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/SimulatorView.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/application/        # TODO make sure to only expose files that are intended for the user 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/sim/
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_constexpr)

target_link_libraries(${PROJECT_NAME} PUBLIC
        raylib
        imgui
        spdlog::spdlog
        )


# Web Configurations 
if( NOT DEFINED ${PLATFORM})
    set(PLATFORM "DESKTOP")
endif()

if (${PLATFORM} STREQUAL "Web")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()