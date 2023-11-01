cmake_minimum_required(VERSION 3.24)
project(3lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(3lab main.cpp set.h set.cpp helpers.h helpers.cpp)
