cmake_minimum_required(VERSION 3.16)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(calculator main.cpp src/calculator.cpp)