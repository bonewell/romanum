cmake_minimum_required(VERSION 3.5)
project(ValidatorTest)
set(CXX_STANDARD 17)

set(GTEST_ROOT /home/bone/git/googletest/build/bin)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    validatortest.cpp
)

target_link_libraries(${PROJECT_NAME}
    GTest::GTest
    GTest::Main
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
