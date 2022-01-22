cmake_minimum_required(VERSION 3.2)
project(Chess LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-g")

add_executable(main main.cpp Piece.cpp Pawn.cpp)
target_link_libraries(main libsfml-graphics.so libsfml-window.so libsfml-system.so)
