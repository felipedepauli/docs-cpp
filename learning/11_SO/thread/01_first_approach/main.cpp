#include <iostream>
#include <thread>
#include <memory>

// We need something to run inside a thread.
void function(int id) {
    for (int i = 0; i < 100 ; i++) {
        std::cout << "Func execution: [" << i+1 << "] -- Inside the thread [" << id << "]" << std::endl;
    }
}



int main() {
    // Create a thread.
    std::thread t1(function, 1);
    std::thread t2(function, 2);
    std::thread t3(function, 3);

    // Wait for the thread to finish.
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
