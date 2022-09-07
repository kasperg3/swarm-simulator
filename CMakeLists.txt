cmake_minimum_required(VERSION 3.16)
project(application)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

set(PROJECT_NAME simulator)

add_subdirectory(swarmsim)

add_subdirectory(example)
