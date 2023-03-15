#include <iostream>

#include "animal.h"
#include "person.h"
#include "object.h"

using namespace std;


int main() {

    Animal* gato = new Animal("Lax");
    Person* humano = new Person("Felipão da Massa");
    Object* object = new Object("Candelabro");

    delete(gato);
    delete(humano);
    delete(object);











    return 0;
}


