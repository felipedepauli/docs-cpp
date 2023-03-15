#include <iostream>
#include <memory>
#include "src/Animal.hpp"


int main(int argc, char *argv[])
{

    std::unique_ptr<Animal::Otter> otter = std::make_unique<Animal::Otter>();
    std::unique_ptr<Animal::SlowLoris> slow = std::make_unique<Animal::SlowLoris>();
    std::unique_ptr<Animal::Tortoise> tortoise = std::make_unique<Animal::Tortoise>();

    otter->eat();
    slow->eat();
    tortoise->eat();
    return 0;
}