#pragma once

class ClassB {
    public:
        ClassB() {
            std::cout << "ClassB constructor" << std::endl;
        }
        int value = 10;
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