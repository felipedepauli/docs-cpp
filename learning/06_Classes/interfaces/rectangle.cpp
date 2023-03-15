#include <shapes.hpp>

Rectangle::Rectangle() {
    std::cout << "Rectangle constructor called" << std::endl;
    width = 0;
    height = 0;
}
Rectangle::~Rectangle() {
    // Destructor
    std::cout << "Rectangle destructor called" << std::endl;
}
int Rectangle::getArea() {
    return width * height;
}