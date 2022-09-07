cmake_minimum_required( VERSION 3.12...3.13 )

project(Experiment
DESCRIPTION "experiment")

set(SOURCES 
    src/Boids.cpp
    src/PropertyPanel.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE SwarmSim)
target_include_directories(${PROJECT_NAME} PUBLIC include)
