#include "Animal.hpp"

namespace Animal {

    Tortoise::Tortoise() {
        name = "Tortoise";
        id = 0;
        age = 10;
    }
    Tortoise::~Tortoise(){};
    void Tortoise::setName(std::string name_) {
        name = name_;
        std::cout << "I'm a " << name << " and I'm eating a banana" << std::endl;
    }
    void Tortoise::eat() {
        std::cout << "I'm a " << name << " and I'm eating a banana" << std::endl;
    }
}