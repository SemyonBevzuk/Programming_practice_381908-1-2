cmake_minimum_required(VERSION 3.15)
project(Task5)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(SQLiteCpp)

add_executable(Task5 main.cpp src/Cinema.cpp include/Cinema.h src/Connector.cpp include/Connector.h src/Session.cpp include/Session.h src/DateTime.cpp include/DateTime.h src/Hall.cpp include/Hall.h SessionTemplate.cpp SessionTemplate.h)

target_link_libraries(Task5 SQLiteCpp)