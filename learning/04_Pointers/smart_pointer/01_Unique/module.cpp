#include <iostream>
#include "./module.h"

using namespace std;

void better_look() {
    cout << endl << endl << endl << endl << endl << endl << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

Rectangle::Rectangle(int l, int b) {
    length  = l;
    breadth = b;
}
int Rectangle::area() {
    return length * breadth; 
}
Rectangle::~Rectangle() {
    cout << "I was killed! ass Rectangle." << endl;
}











