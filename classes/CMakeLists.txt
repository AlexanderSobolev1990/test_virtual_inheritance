cmake_minimum_required(VERSION 3.7)
project(classes LANGUAGES CXX)
get_filename_component(SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ ABSOLUTE) # Путь к корневой директории решения (solution)
message(STATUS "CMAKE_VERSION: ${CMAKE_VERSION}, PROJECT_NAME: ${PROJECT_NAME}, SOLUTION_DIR: ${SOLUTION_DIR}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(BLAS REQUIRED)
find_package(Armadillo REQUIRED)

add_library(${PROJECT_NAME} STATIC classes.h classes.cpp)

target_link_libraries(${PROJECT_NAME}
    ${ARMADILLO_LIBRARIES}
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )

# Включить замеры времени сборки
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CMAKE_COMMAND} -E time")
