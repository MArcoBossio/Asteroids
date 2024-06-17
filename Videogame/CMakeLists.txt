cmake_minimum_required(VERSION 3.22)
project(Videogame)

set(CMAKE_CXX_STANDARD 14)

add_executable(Videogame main.cpp Player.cpp Player.h Entity.cpp Entity.h Bullet.cpp Bullet.h
        Asteroids.cpp Asteroids.h Game.cpp Game.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Videogame sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET Videogame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:Videogame>/assets)

set(GTEST_DIR googletest)
include_directories(${GTEST_DIR}/include ${GTEST_DIR}/include)
add_subdirectory(googletest)
add_subdirectory(test/unit_tests)