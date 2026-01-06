#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const int SIZE = 6; 
    Animal* animals[SIZE];

    int i = 0;
    while (i < SIZE / 2) {
        animals[i] = new Dog();
        i++;
    }
    while (i < SIZE) {
        animals[i] = new Cat();
        i++;
    }

    std::cout << "\n--- Calling sounds ---\n";
    i = 0;
    while (i < SIZE) {
        animals[i]->makeSound();
        i++;
    }

    std::cout << "\n--- Deleting animals as Animal* ---\n";
    i = 0;
    while (i < SIZE) {
        delete animals[i];
        i++;
    }
    return 0;
}