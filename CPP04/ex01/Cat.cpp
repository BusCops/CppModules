#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	brain = new Brain();
	std::cout << "Cat Default contructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	brain = new Brain();
	std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *(other.brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meao.." << std::endl;
}
