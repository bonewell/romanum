set(TestSuite ${CompanentName}Test)

add_executable(${TestSuite}
    validatortest.cpp
    convertertest.cpp
)

target_include_directories(${TestSuite} PRIVATE
    ${CMAKE_SOURCE_DIR}/core
)

target_link_libraries(${TestSuite}
    ${PROJECT_NAME}::${CompanentName}
    GTest::GTest
    GTest::Main
)

add_test(${TestSuite} ${TestSuite})
