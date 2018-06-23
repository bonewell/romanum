set(CompanentName ${PROJECT_NAME}Core)

add_library(${CompanentName}
    romannumber.cpp
    validator.cpp
    converter.cpp
)
add_library(${PROJECT_NAME}::${CompanentName} ALIAS ${CompanentName})

add_subdirectory(tests)
