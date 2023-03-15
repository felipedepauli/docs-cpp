#include <iostream>
#include <string.h>

// A struct is a data type that can be used to group items of possibly different types into a single type.
// It is a user-defined data type in C/C++.

typedef struct {
    char    name[20];
    int     age;
    void    setAge(int age) {
        this->age = age;
    }
} person_t;

int main(int argc, char const *argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <age>" << std::endl;
        return 1;
    }

    person_t person;
    strcpy(person.name, "Vráuzio");
    person.setAge(atoi(argv[1]));

    if (person.age > 18 && person.age < 38) {
        std::cout << "Mr. " << person.name << " is a boring adult. He's "<< person.age << " years old." << std::endl;
    } else if (person.age < 18) {
        std::cout << "Mr. " << person.name << " is a fucking child. He's "<< person.age << " years old." << std::endl;
    } else {
        std::cout << "Mr. " << person.name << " is almost dead. He's "<< person.age << " years old." << std::endl;
    }
    
    return 0;
}