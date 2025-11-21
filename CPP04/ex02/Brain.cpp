#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain &other)
{
	std::cout << "Brain copy constructor called";
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100 ; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}