#include <iostream>
#include <shapes.hpp>




int main() {

    Rectangle rect;
    rect.setWidth(5);
    rect.setHeight(7);
    std::cout << "Total area: " << rect.getArea() << std::endl;

    Triangle tri;
    tri.setWidth(5);
    tri.setHeight(7);
    std::cout << "Total area: " << tri.getArea() << std::endl;

    return 0;
}