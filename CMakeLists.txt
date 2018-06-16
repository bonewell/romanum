cmake_minimum_required(VERSION 3.5)
project(Romanum)
set(CXX_STANDARD 17)

add_library(${PROJECT_NAME}
    romannumber.cpp
    validator.cpp
)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set(GTEST_ROOT /home/bone/git/googletest/build/bin)
enable_testing()
find_package(GTest REQUIRED)

add_subdirectory(tests)
