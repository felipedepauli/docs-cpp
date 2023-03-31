#include <stdio.h>
#include <cstdlib>
#include <chrono>
#include <thread>

int main(int argc, char const *argv[])
{
    int qdtloop = 0;
    if(argc <= 1) {
        qdtloop = 1000;
    } else {
        qdtloop = std::atoi(argv[1]);
    }
    
    for(int i = 0; i < qdtloop;i++) {
        printf("Iteracao %d de %d\n", i, qdtloop);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}