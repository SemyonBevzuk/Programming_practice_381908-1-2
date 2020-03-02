cmake_minimum_required(VERSION 3.10)
project(Task1)

set(CMAKE_CXX_STANDARD 14)

include_directories(big_integer)

add_subdirectory(big_integer)
add_subdirectory(big_integer_tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../lib ${CMAKE_CURRENT_BINARY_DIR}/lib)
