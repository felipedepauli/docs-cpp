#include <iostream>
#include <thread>

void insanity() {
    std::cout << "Hello, Insanity!" << std::endl;
}


int main() {

    std::cout << "Hello, Mother Fucker!" << std::endl;


    std::thread t1([]() {
        std::cout << "Hello, World!" << std::endl;
    });
    std::thread t2(insanity);

    t1.join();
    t2.join();

    return 0;
}