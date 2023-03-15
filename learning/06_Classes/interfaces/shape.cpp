#include <shapes.hpp>

Shape::Shape() {
    std::cout << "Shape constructor called" << std::endl;
    width = 0;
    height = 0;
}
Shape::~Shape() {
    // Destructor
    std::cout << "Shape destructor called" << std::endl;
}
void Shape::setWidth(int w) {
    width = w;
}
void Shape::setHeight(int h) {
    height = h;
}
