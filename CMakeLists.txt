cmake_minimum_required(VERSION 3.13)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

add_library(Matrix matrix.cpp solveSystem.cpp fileOperations.cpp arithmeticOperations.cpp boolFunctions.cpp triangularFactorization.cpp matrixTransformations.cpp additionalInformation.cpp gaussianElimination.cpp gaussSeidel.cpp operatorOverloading.cpp gaussJacobi.cpp find_zero.cpp)

add_executable(mat matrix.cpp main.cpp solveSystem.cpp fileOperations.cpp arithmeticOperations.cpp boolFunctions.cpp triangularFactorization.cpp matrixTransformations.cpp additionalInformation.cpp gaussianElimination.cpp gaussSeidel.cpp operatorOverloading.cpp gaussJacobi.cpp gaussJacobi.cpp find_zero.cpp)