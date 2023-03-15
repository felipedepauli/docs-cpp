#include <iostream>
#include "./person.h"

Person::Person (std::string n) {
    std::cout << "Hello! I'm the Person and I was created!!! \\o/ My name is " << n << std::endl;
    name = n;
}

Person::~Person () {
    std::cout << "The person " << name << " is dead... =/" << std::endl;
}
