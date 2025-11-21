#include "AMateria.hpp"
#include "Concrete.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other)
{
	*this = other;
}
Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		//AMateria::operator=(other); need to know what to do here ;D
	}
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

///////////////////////////////////////////////////////////////////////////////////

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other)
{
	*this = other;
}
Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		//AMateria::operator=(other); need to know what to do here ;D
	}
	return *this;
}

Cure::~Cure()
{}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}
