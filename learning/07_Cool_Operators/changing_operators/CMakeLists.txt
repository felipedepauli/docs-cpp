cmake_minimum_required(VERSION 3.10)

set(
    THIS
    Overload
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SOURCE
    main.cpp
    overload.cpp
)

add_executable(${THIS} ${SOURCE})