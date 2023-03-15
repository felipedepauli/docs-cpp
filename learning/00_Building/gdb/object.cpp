#include <iostream>
#include "./object.h"

Object::Object (std::string n) {
    std::cout << "Hello! I'm the Object and I was created!!! \o/ My name is " << n << std::endl;
    name = n;
}

Object::~Object () {
    std::cout << "The Object " << name << " is broken... =/" << std::endl;
}
