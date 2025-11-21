#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default contructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat parameterized constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &other)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat" << std::endl;
}
