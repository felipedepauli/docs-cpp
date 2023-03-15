#include <shapes.hpp>

Triangle::Triangle() {
    std::cout << "Triangle constructor called" << std::endl;
    width = 0;
    height = 0;
}
Triangle::~Triangle() {
    // Destructor
    std::cout << "Triangle destructor called" << std::endl;
}
int Triangle::getArea() {
    return (width * height) / 2;
}