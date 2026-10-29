
cmake_minimum_required(VERSION 3.10)

project(numerical-computation1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(numerical-computation1
    src/statistics.cpp
    src/ndarray.cpp
    src/aggregation.cpp
)

target_include_directories(numerical-computation1
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(statistics_example
    examples/statistics_example.cpp
)

target_link_libraries(statistics_example
    numerical-computation1
)

add_executable(ndarray_example
    examples/ndarray_example.cpp
)
add_executable(aggregation_example
     
     examples/aggregation_example.cpp
)
target_link_libraries(ndarray_example
    numerical-computation1
)

enable_testing()

add_executable(test_ndarray
    tests/test_ndarray.cpp
)

target_link_libraries(test_ndarray
    numerical-computation1
)

add_test(
    NAME ndarray_test
    COMMAND test_ndarray
)
