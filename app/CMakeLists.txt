cmake_minimum_required( VERSION 3.12...3.13 )

project(Experiment
DESCRIPTION "experiment")

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SwarmSim)