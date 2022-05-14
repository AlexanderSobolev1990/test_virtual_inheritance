cmake_minimum_required(VERSION 3.5)

project(test_virtual_inheritance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(BLAS REQUIRED)
find_package(Armadillo REQUIRED)

add_executable(test_virtual_inheritance
    classes.h
    main.cpp
    )

target_link_libraries(${PROJECT_NAME}
    ${ARMADILLO_LIBRARIES}
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
