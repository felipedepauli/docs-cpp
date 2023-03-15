cmake_minimum_required(VERSION 3.10)

set(THIS Vectors_Sorting)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SOURCE
    main.cpp
    sort.cpp
)

add_executable(${THIS} ${SOURCE})

add_library(
    sort.o
    STATIC
    sort.cpp
)