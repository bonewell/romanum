set(CompanentName ${PROJECT_NAME}Core)

add_library(${CompanentName}
    romannumber.cpp
    validator.cpp
    converter.cpp
)
add_library(${PROJECT_NAME}::${CompanentName} ALIAS ${CompanentName})
target_compile_features(${CompanentName} PRIVATE cxx_std_17)

add_subdirectory(tests)
