#include <iostream>

using namespace std;

int main() {



    int number_one = 10;
    int number_two = 20;

    int min = (number_one < number_two) ? number_one : number_two; 
    int max = (number_one > number_two) ? number_one : number_two; 

    for (int i = min; i < max ; i++) {
        cout << i << endl;
    }

    return 0;
}


