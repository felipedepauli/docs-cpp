#include <pthread.h>
#include <iostream>

void* print_thread(void* data) {
    std::cout << "I'm printing inside the thread" << std::endl;
    return nullptr;
}

int main() {
    pthread_t thread_id;
    int status;

    status = pthread_create(&thread_id, NULL, print_thread, NULL);

    if(status != 0) {
        std::cerr << "Erro ao criar a thread" << std::endl;
        return 1;
    }

    // Wait for thread return
    pthread_join(thread_id, NULL);

    std::cout << "Main and thread end together!" << std::endl;
    return 0;
}