cmake_minimum_required(VERSION 3.5)
project(Romanum)
set(CXX_STANDARD 17)

set(GTEST_ROOT /home/bone/git/googletest/build/bin)
enable_testing()
find_package(GTest REQUIRED)

add_subdirectory(core)
add_subdirectory(cmd)
