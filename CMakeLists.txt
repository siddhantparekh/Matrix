cmake_minimum_required(VERSION 3.13)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

add_library(Matrix matrix.cpp matrix.hpp main.cpp)

add_executable(mat matrix.cpp main.cpp)