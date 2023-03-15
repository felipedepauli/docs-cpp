#include <iostream>

/*
    CLASS A's object creates an object of class B and hold a pointer to it
    CLASS C's object creates an pointer to that same class B's object
    CLASS A's object is deleted
    ------
    PROBLEM: CLASS B's object is not deleted
*/

class ClassB {
    public:
        ClassB() {
            std::cout << "ClassB constructor" << std::endl;
        }
        ~ClassB() {
            std::cout << "ClassB destructor" << std::endl;
        }
        int value;
};
class ClassA {
    public:
        ClassB *b_ptr;
        ClassA() {
            std::cout << "ClassA constructor" << std::endl;
            b_ptr = new ClassB();
        }
        ~ClassA() {
            std::cout << "ClassA destructor" << std::endl;
            delete(b_ptr);  // ***************************************
        }
        int a;
};
class ClassC {
    public:
        ClassB *b_ptr;
        ClassC(ClassB* b_ptr_) {    // ********************************
            std::cout << "ClassC constructor" << std::endl;
            b_ptr = b_ptr_;         // ********************************
        }
        ~ClassC() {
            std::cout << "ClassC destructor" << std::endl;
        }
        int c;
};

int main() {
    ClassA* obA = new ClassA();             // obA has a pointer to ClassB's object with b = 10
    ClassC* obC = new ClassC(obA->b_ptr);   // obC is instantiated with a pointer to the same ClassB's object

    obC->b_ptr->value = 12;
    obA->b_ptr->value = obA->b_ptr->value * 2;

    std::cout << "obB.value = " << obA->b_ptr->value << std::endl;

    delete(obA);

    obA->b_ptr->value = 12;
    std::cout << "obB.value = " << obA->b_ptr->value << std::endl;

    delete(obC);

    return 0;
}