#include "Animal.hpp"

Animal::Animal()
: type()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
: type(type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}
Animal::Animal(Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

