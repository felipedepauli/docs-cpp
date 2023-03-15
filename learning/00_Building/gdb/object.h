#ifndef __USER_OBJECT__
#define __USER_OBJECT__

#include <iostream>

class Object {
    private:
        std::string name;
    public:
        Object(std::string);

        ~Object(void);
};

#endif
