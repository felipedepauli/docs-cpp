#include <iostream>
#include <memory>
#include "./module.h"

using namespace std;

void better_look(void);
void fun(void);

int main() {
   

    fun();
    cout << "Live keeps" << endl;



    better_look();
    return 0;
}

void fun() {
    shared_ptr<Rectangle> rec(new Rectangle(10, 20));
    cout << "The area of 10 by 20 is " << rec->area() << endl;

    shared_ptr<Rectangle> rec2;
    rec2 = rec; // Now it's possible.

    rec->area(); // Only one can point to the space.
    cout << "The area of 10 by 20 is " << rec2->area() << endl;
    // Look as only one killing message is shown.
}
