#include <iostream>
#include "./animal.h"

Animal::Animal (std::string n) {
    std::cout << "Hello! I'm the Animal and I was created!!! \\o/ My name is " << n << std::endl;
    name = n;
}

Animal::~Animal () {
    std::cout << "The Animal " << name << " is dead... =/" << std::endl;
}