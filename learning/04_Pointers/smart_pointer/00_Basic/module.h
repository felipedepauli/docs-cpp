#ifndef __USER_MODULE__
#define __USER_MODULE__

#include <iostream>

void better_look(void);
void fun(void);

class Rectangle {
    private:
        int length;
        int breadth;
};


template<class T>
class SmartPtr {
    private:
        T* ptr;
    public:
    //  Constructor
        explicit SmartPtr(T* p = NULL) {
            ptr = p;        // ptr receives an address where it will point to
        }

    //  Destructor
        ~SmartPtr() {
            delete(ptr);    // when the object is destroied, the destructor will delete the ptr
            std::cout << "Hey, my friedn!!! I has deleted the pointer object. ;)" << std::endl;
        }

    //  It's something. I think it's the return of new call
    //  It doesn't return the instance of the class, but the instance of the pointer inside the class
        T& operator*() {
            return *ptr;
        }
};

#endif