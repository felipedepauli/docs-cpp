#include <iostream>
#include <string>

class Animal {
    public:
        struct Nationality {
            virtual void        setCountry(std::string) = 0;
            virtual std::string getCountry() = 0;
        };
        Animal(){}

        int attack;
        int deffence;

        int getAttack() {
            return attack;
        }
        int getDeffence() {
            return deffence;
        }

};

class Cat : public Animal::Nationality {
    private:
        std::string country;

    public:
        void setCountry(std::string country_) {
            country = country_;
        }
        std::string getCountry() {
            return "Brazil";
        }
        Animal *animal;
        Cat(int attack_, int deffence_) {
            animal = new Animal;
            animal->attack = attack_;
            animal->deffence = deffence_;
        }
        ~Cat() {
            delete(animal);
        }
};



int main() {

    Cat cat(10, 10);
    std::cout << "Attack: " << cat.animal->getAttack() << std::endl;
    std::cout << "Deffence: " << cat.animal->getDeffence() << std::endl;

    // Notice we don't need to delete de cat.
    // That's because we are not creating a new Cat object using new.
    // When we use new, we are creating a new Cat object in the heap.
    // Instead, we are creating a new Cat object inside the stack.
    // All objects created inside the stack are automatically deleted when the program ends.
    return 0;
}