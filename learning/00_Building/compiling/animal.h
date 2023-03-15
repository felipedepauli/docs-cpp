#ifndef __USER_ANIMAL__
#define __USER_ANIMAL__

#include <iostream>

class Animal {
    private:
        std::string name;
    public:
        Animal(std::string);

        ~Animal(void);
};

#endif
