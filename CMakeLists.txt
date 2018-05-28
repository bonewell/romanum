cmake_minimum_required(VERSION 3.5)
project(ValidatorTest)

set(GTEST_ROOT /home/kkolodiy/git/google/googletest/build/bin)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME}
    tst_validatortest.cpp
)

target_link_libraries(${PROJECT_NAME}
    GTest::GTest
    GTest::Main
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
