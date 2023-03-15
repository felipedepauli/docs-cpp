cmake_minimum_required(VERSION 3.10)

project(Callback)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SOURCE
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)