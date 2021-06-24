cmake_minimum_required(VERSION 3.19)
project(Final)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(Final main.cpp src/CharacterBuilder.cpp src/CharacterBuilder.h src/UserGUI.cpp src/UserGUI.h src/Game.cpp src/Game.h)