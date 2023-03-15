#ifndef __USER_PERSON__
#define __USER_PERSON__

#include <iostream>

class Person {
    private:
        std::string name;
    public:
        Person(std::string);

        ~Person(void);
};

#endif
