cmake_minimum_required(VERSION 3.10)
project(Task3)

set(CMAKE_CXX_STANDARD 14)

include_directories(dictionary)

add_subdirectory(dictionary)
add_subdirectory(dictionary_test)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../lib ${CMAKE_CURRENT_BINARY_DIR}/lib)