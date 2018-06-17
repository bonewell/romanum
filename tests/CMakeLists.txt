set(TEST_SUITE ${PROJECT_NAME}Test)

add_executable(${TEST_SUITE}
    validatortest.cpp
    convertertest.cpp
)

target_include_directories(${TEST_SUITE} PRIVATE
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(${TEST_SUITE}
    Romanum::Romanum
    GTest::GTest
    GTest::Main
)

add_test(${TEST_SUITE} ${TEST_SUITE})
