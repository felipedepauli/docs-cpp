cmake_minimum_required(VERSION 3.0)

set(
    SOURCE
    Otter.cpp
    SlowLoris.cpp
    Tortoise.cpp
)

add_library(
    Animals
    STATIC
    ${SOURCE}
)