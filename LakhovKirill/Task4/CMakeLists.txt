cmake_minimum_required(VERSION 3.15)
project(Task4)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(SQLiteCpp)

add_executable(Task4 main.cpp)

target_link_libraries(Task4 SQLiteCpp)