#include <iostream>
#include <vector>
#include <map>

using namespace std;

// An iterator is an object that points to an element in a container.
// It allows us to navigate through the elements of a container.
// -> Iterators are used to access the elements of a container.
// -> Iterators are used to traverse the elements of a container.
// -> Iterators are used to point to the elements of a container.

int main(int argc, char *argv[]) {

    // It defines a vector with three products.
    vector<string> products = { "box", "ball", "book", "pen", "pencil" };

    // We can look at the elements of the vector int the old fashion way.
    cout << products[0] << endl;
    // If you want more one, you have to use a loop.
    for (int i = 0; i < products.size(); i++) {
        cout << products[i] << endl;
    }

    cout << "--------------------------------" << endl;

    // We can use an iterator to access the elements of a container.
    // The iterator is a pointer to the elements of a container.
    vector<string>::iterator it;

    // Let's print the first element.
    it = products.begin();
    cout << *it << endl;
    // And the second element.
    it++;
    cout << *it << endl;
    // And the last element.
    it = products.end();
    it--;
    cout << *it << endl;


    cout << "--------------------------------" << endl;


    // But instead of using increment and decrement, we can use the
    // following methods:
    // -> advance: moves the iterator forward.
    // -> distance: returns the distance between two iterators.
    // -> next: returns the next iterator.
    // -> prev: returns the previous iterator.

    // Advance allows you go from 0 to some specific position.
    // Always from the place it is, and go forward!!
    it = products.begin();
    advance(it, 3); // Will be "pen"
    cout << "It must be pen = " << *it << endl;

    // If we go one forward, instead the beginning, we will get the
    // second element. Then, advance will move the iterator forward from there.
    it = products.begin();
    it++;
    advance(it, 3); // Will be "pencil"
    cout << "It must be pencil = "  << *it << endl;
    advance(it, -2); // Will be "book"
    cout << "It must be book = "    << *it << endl;
    advance(it, -1); // Will be "ball"
    cout << "It must be ball = "    << *it << endl;

    cout << "--------------------------------" << endl;



    return 0;
}