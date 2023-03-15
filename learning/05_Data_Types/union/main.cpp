#include <iostream>
#include <string.h>
#include "./union.hpp"

// Union is a data type that can store different data types in the same memory location.
// You can define a union with many members, but only one member can contain a value at any given time.
// Unions provide an efficient way of using the same memory location for multiple purposes.
// For example, you can use a union to overlay a structure on top of a character array.
// You can also use a union to access the same memory location in different ways.

int main(int argc, char* argv[]) {
    std::cout << "Hello, Union!" << std::endl;

    Data data;
    data.i = 10;
    std::cout << data.i << std::endl;
    data.f = 220.5;
    std::cout << data.i << std::endl;
    std::cout << data.f << std::endl;
    strcpy(data.str, "C Programming");
    std::cout << data.str << std::endl;

    Gentee gentee;
    gentee.x = 10;
    gentee.y = 20;
    gentee.z = 30;
    std::cout << gentee.x << std::endl;
    std::cout << gentee.y << std::endl;
    std::cout << gentee.z << std::endl;

    return 0;
}