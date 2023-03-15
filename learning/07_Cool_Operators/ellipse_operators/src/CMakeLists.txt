cmake_minimum_required(VERSION 3.0)

set(THIS Main)          # Define the THIS variable

set(SOURCE              # Define the SOURCE variable
    ellipse_operators.cpp
)

add_library(
    ${THIS}             # Name of the library
    STATIC              # Type of the library
    ${SOURCE}           # Source files
)