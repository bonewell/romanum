set(TestSuite ${CompanentName}Test)

add_executable(${TestSuite}
    validatortest.cpp
    convertertest.cpp
)

target_include_directories(${TestSuite} PRIVATE
    ${CMAKE_SOURCE_DIR}/core
    ${gmock_SOURCE_DIR}/include
)

target_link_libraries(${TestSuite}
    ${PROJECT_NAME}::${CompanentName}
    gtest
    gtest_main
)

add_test(${TestSuite} ${TestSuite})
