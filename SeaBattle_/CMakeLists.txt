cmake_minimum_required(VERSION 3.17)
project(SeaBattle_)

set(CMAKE_CXX_STANDARD 20)

add_executable(SeaBattle_ main.cpp GameField.cpp GameField.h Game.cpp Game.h)