cmake_minimum_required(VERSION 3.5)
project(Romanum)
set(CXX_STANDARD 17)

include(GTest.cmake)

add_subdirectory(core)
add_subdirectory(cmd)
