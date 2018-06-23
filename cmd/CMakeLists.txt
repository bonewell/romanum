set(CompanentName ${PROJECT_NAME}Cmd)

add_executable(${CompanentName}
    main.cpp
)
target_include_directories(${CompanentName} PRIVATE
    ${CMAKE_SOURCE_DIR}/core
)
target_link_libraries(${CompanentName} ${PROJECT_NAME}::RomanumCore)
