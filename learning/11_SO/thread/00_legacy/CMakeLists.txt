cmake_minimum_required(VERSION 3.0)

project(Legacy)

set(CMAKE_CXX_STANDARD 11)

set(
    SOURCE
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    -pthread
)