cmake_minimum_required(VERSION 3.22)
project(Videogame)

set(CMAKE_CXX_STANDARD 11)

add_executable(Videogame main.cpp Player.cpp Player.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Videogame sfml-graphics sfml-window sfml-system)

