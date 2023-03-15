cmake_minimum_required(VERSION 3.0)

project(Dependencies)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SOURCE
    main.cpp
)

add_executable(Dependencies ${SOURCE})