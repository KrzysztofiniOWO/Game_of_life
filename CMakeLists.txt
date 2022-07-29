cmake_minimum_required(VERSION 3.22)
project(Game_of_life)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game_of_life main.cpp AlwaysNextTurn.h CommandSource.h Donut.h GameControl.h GameOfLife.h ManualTurns.h Roller.h AlwaysNextTurn.cpp Donut.cpp GameControl.cpp GameOfLife.cpp ManualTurns.cpp Roller.cpp)
