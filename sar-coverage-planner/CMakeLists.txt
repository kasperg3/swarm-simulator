cmake_minimum_required( VERSION 3.12...3.13 )

project( SarCoveragePlanner
         VERSION 1.0.0
         DESCRIPTION "Multi robot coverage planner" )


# Libraries 

# spdLog
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

# Computation Geometry Algorithms Library
find_package(CGAL REQUIRED COMPONENTS Core)

# Create a shared library
add_library(${PROJECT_NAME} OBJECT)

target_sources(${PROJECT_NAME} 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/planner/CoveragePlanner.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/Log.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/CGALUtil.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/planner/decomposition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/planner/BCD.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/planner/WeaklyMonotone.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/planner        # TODO make sure to only expose files that are intended for the user 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/core 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

target_compile_features(${PROJECT_NAME} PUBLIC cxx_constexpr)

target_link_libraries(${PROJECT_NAME} PUBLIC
        spdlog::spdlog 
        CGAL::CGAL # TODO do not inclode all of CGAL
        )
