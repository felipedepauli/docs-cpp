cmake_minimum_required(VERSION 3.0)

project(UnionProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SOURCE
    main.cpp
    union.cpp
    union.hpp
)

add_executable(
    Union
    ${SOURCE}
)