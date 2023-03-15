#include <iostream>
#include <thread>
#include <string>

void func(std::string name, bool &lock, int &count) {
    for (int i = 0; i < 10000 ; i++) {
        while(true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
            if (!lock) {
                lock = true;
                std::cout << "Func [" << name << "] : " << ++count << std::endl;
                lock = false;
                break;
            } else {
                continue;
            }
        }
    }
}

int main() {

    int count = 0;
    bool lock = false;

    std::thread t1(func, "t1", std::ref(lock), std::ref(count));
    std::thread t2(func, "t2", std::ref(lock), std::ref(count));

    t1.join();
    t2.join();


    return 0;
}