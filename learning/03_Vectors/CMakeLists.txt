cmake_minimum_required(VERSION 3.10)

project("Vectors")

include_directories(
    ${PROJECT_SOURCE_DIR}/sort
)
add_subdirectory(sort)

set(
    SOURCE
    main.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCE}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    sort.o
)