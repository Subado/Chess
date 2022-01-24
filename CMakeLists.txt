cmake_minimum_required(VERSION 3.2)
project(Chess LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-g")

set(CMAKE_MODULE_PATH "D:\SFML-2.5.1\lib\cmake\SFML")

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

add_executable(main main.cpp Piece.cpp Pawn.cpp)
target_link_libraries(main sfml-graphics)
