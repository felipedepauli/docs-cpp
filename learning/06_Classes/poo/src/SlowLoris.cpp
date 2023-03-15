#include "Animal.hpp"

namespace Animal {

    SlowLoris::SlowLoris() {
        name = "SlowLoris";
        id = 0;
        age = 10;
    }
    SlowLoris::~SlowLoris(){};
    void SlowLoris::setName(std::string name_) {
        name = name_;
        std::cout << "I'm a " << name << " and I'm eating a banana" << std::endl;
    }
    void SlowLoris::eat() {
        std::cout << "I'm a " << name << " and I'm eating a banana" << std::endl;
    }
}