#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	brain = new Brain();
	std::cout << "Dog Default contructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	brain = new Brain();
	std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	brain = new Brain();
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor called" << std::endl;
}
#include <stdio.h>

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bark.." << std::endl;
}