# Include the Google Test library
include_directories(${GTEST_DIR}/include ${GTEST_DIR})

# Add your test source files
set(TEST_SOURCES AsteroidsTest.cpp PlayerTest.cpp)

# Create a test executable
add_executable(runUnitTests ${TEST_SOURCES})

# Link the Google Test libraries
target_link_libraries(runUnitTests gtest gtest_main)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set_target_properties(runUnitTests PROPERTIES POSITION_INDEPENDENT_CODE ON)