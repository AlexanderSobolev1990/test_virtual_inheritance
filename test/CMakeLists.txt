cmake_minimum_required(VERSION 3.7)
project(test_classes LANGUAGES CXX)
message(STATUS "CMake version: ${CMAKE_VERSION}, Project: ${PROJECT_NAME}")

enable_testing(true)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)
find_package(BLAS REQUIRED)
find_package(Armadillo REQUIRED)
#include_directories(/usr/include/python3.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# test_classes
add_executable(test_classes test_classes.cpp)
add_test(NAME test_classes COMMAND test_classes)
target_link_libraries(test_classes classes ${Boost_LIBRARIES})
target_include_directories(test_classes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../classes)
