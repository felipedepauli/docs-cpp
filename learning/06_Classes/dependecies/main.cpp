#include <iostream>
#include <smart_pointers.h>





int main() {

    ClassA* obA = new ClassA();             // obA has a pointer to ClassB's object with b = 10
    ClassC* obC = new ClassC(obA->b_ptr);   // obC is instantiated with a pointer to the same ClassB's object

    obC->b_ptr->value = 12;
    obA->b_ptr->value = obA->b_ptr->value * 2;

    std::cout << "obB.value = " << obA->b_ptr->value << std::endl;

    delete(obA);
    delete(obC);

    return 0;
}