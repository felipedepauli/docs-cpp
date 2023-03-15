#pragma once
#include <string>
#include <iostream>

namespace Animal {

class Animal {
    protected:
        std::string     name;
        int             id;
        int             age;
        int             weight;
    public:
        virtual void setName(std::string name_) = 0;
        virtual void eat() = 0;
};

class Otter     : public Animal {
    private:
        int     whiskerLength;
    public:
        Otter();
        ~Otter();
        void setName(std::string);
        void eat();
};

class Tortoise  : public Animal {
    public:
        Tortoise();
        ~Tortoise();
        void setName(std::string);
        void eat();
};
class SlowLoris : public Animal {
    public:
        SlowLoris();
        ~SlowLoris();
        void setName(std::string);
        void eat();
};

}