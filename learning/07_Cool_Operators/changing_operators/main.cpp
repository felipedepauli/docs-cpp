#include "../include/overload.hpp"

int main() {


    little_box_t box1;
    little_box_t box2;

    std::cout << "box1 == box2: " << ((box1 == box2) ? "Objetos Iguais" : "Objetos Diferentes") << std::endl;

    box1.type = CAR;

    std::cout << "box1 == box2: " << ((box1 == box2) ? "Objetos Iguais" : "Objetos Diferentes") << std::endl;

    box1.type = TRUCK;

    std::cout << "box1 == box2: " << ((box1 == box2) ? "Objetos Iguais" : "Objetos Diferentes") << std::endl;


    std::cout << "Im the Overload's Main!" << std::endl;
    return 0;
}