cmake_minimum_required(VERSION 3.15)
project(Task6)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task6 main.cpp src/Game.cpp include/Game.h src/Player.cpp include/Player.h src/View.cpp include/View.h src/Field.cpp include/Field.h src/Matrix.cpp include/Matrix.h src/Ship.cpp include/Ship.h src/Hit.cpp include/Hit.h src/Bot.cpp include/Bot.h)

