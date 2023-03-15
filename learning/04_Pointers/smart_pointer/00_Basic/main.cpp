#include <iostream>
#include "./module.h"

using namespace std;

void better_look();

int main() {

    // fun(); // This is how to get Memory Leak

    SmartPtr<int> ptr_int(new int());
    *ptr_int = 20;

    cout << "The number inside the ptr_int is " << *ptr_int << endl;

    SmartPtr<float> ptr_float(new float());
    *ptr_float = (float)20.1;

    cout << "The number inside the ptr_float is " << *ptr_int << endl;



    


    better_look();
    return 0;
}
