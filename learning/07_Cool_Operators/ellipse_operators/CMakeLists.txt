cmake_minimum_required(VERSION 3.10)

project(EllipseOperator)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

set(
    SOURCE
    main.cpp
)

add_executable(
    EllipseOperator
    ${SOURCE}
)

target_link_libraries(
    EllipseOperator
    PUBLIC
    Main
)