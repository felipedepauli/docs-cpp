#include <iostream>

class A {
    public:
        long long numero = 51651154651561651;
};

long long funE() {
    A* a = new A();
    delete a;
    return a->numero;   
}

long long funD() {
    A* a;
    return a->numero;  
    return funE(); 
}

long long funC() {
    A* a = nullptr;
    return a->numero;
    return funD();
}

long long funB() {
    return funC();
}

long long funA() {
    return funB();
}

int main(int argc, char const *argv[])
{
    std::cout << funA() << std::endl;
    return 0;
}
