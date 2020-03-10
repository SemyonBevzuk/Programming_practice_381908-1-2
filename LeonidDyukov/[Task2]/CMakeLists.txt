cmake_minimum_required(VERSION 3.10)
project(Task2)

set(CMAKE_CXX_STANDARD 14)

include_directories(matrix)

add_subdirectory(matrix)
add_subdirectory(matrix_tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest)
