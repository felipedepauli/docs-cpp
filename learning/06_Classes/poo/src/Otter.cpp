#include "Animal.hpp"

namespace Animal {

    Otter::Otter() {
        name = "Otter";
        id = 0;
        age = 10;
    }
    Otter::~Otter(){};
    void Otter::setName(std::string name_) {
        name = name_;
        std::cout << "I'm a " << name << " and I'm eating a banana" << std::endl;
    }
    void Otter::eat() {
        std::cout << "I'm a " << name << " and I'm eating a banana" << std::endl;
    }
}