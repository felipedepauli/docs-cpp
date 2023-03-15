cmake_minimum_required(VERSION 3.0)

project(MyClasses)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

set(
    SOURCE
    main.cpp
)

add_executable(
    Classes
    ${SOURCE}
)

target_link_libraries(
    Classes
    PUBLIC
    Animals
)