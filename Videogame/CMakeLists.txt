cmake_minimum_required(VERSION 3.22)
project(Videogame)

set(CMAKE_CXX_STANDARD 14)

add_executable(Videogame main.cpp src/Player.cpp src/Player.h src/Entity.cpp src/Entity.h
        src/Bullet.cpp src/Bullet.h src/Asteroids.cpp src/Asteroids.h src/Game.cpp src/Game.h)

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
# Add your test source files
set(TEST_SOURCES AsteroidsTest.cpp PlayerTest.cpp ../Asteroids.cpp)