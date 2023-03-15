cmake_minimum_required(VERSION 3.10)

project(Interfaces)

include_directories(
    include
)
set(
    SOURCES
    main.cpp
    shape.cpp
    rectangle.cpp
    triangle.cpp
)

add_executable(Interfaces ${SOURCES})