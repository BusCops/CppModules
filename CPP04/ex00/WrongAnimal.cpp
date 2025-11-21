#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
: type(type)
{
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}


void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal" << std::endl;
}
