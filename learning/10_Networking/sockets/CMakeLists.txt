cmake_minimum_required(VERSION 3.0)

project(Connex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    SERVER_SOURCE
    src/server.cpp
)
set(
    CLIENT_SOURCE
    src/client.cpp
)

include_directories(include)

add_executable(server ${SERVER_SOURCE})
add_executable(client ${CLIENT_SOURCE})

target_link_libraries(server pthread)
target_link_libraries(client pthread)