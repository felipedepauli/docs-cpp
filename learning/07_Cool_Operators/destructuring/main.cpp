#include <iostream>
#include <utility>
#include <memory>

typedef struct {
    int a;
    int b;
} MyStruct;

void func(int a, int b) {
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
}

std::unique_ptr<MyStruct> func2() {
    MyStruct ms = {1, 2};
    return std::make_unique<MyStruct>(ms);
}


int main(int argc, char *argv[]) {


    MyStruct ms = {1, 2};
    std::cout << "oi " << __cplusplus << std::endl;

    std::unique_ptr<MyStruct> ms2 = func2();
    std::cout << "ms2->a: " << ms2->a << " ms2->b: " << ms2->b << std::endl;

    return 0;
}
