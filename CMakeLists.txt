cmake_minimum_required(VERSION 3.2)
project(Chess LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g -Wall")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules")
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SFML")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)
	set(SFML_STATIC_LIBRARIES TRUE)
endif()


add_executable(main main.cpp Piece.cpp Pawn.cpp)
target_link_libraries(main sfml-graphics)
