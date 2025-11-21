#include "AMateria.hpp"
#include "Concrete.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{}

AMateria::AMateria(std::string const &type)
:type(type)
{}
	
AMateria::AMateria(const AMateria &other)
{
	*this = other;
}


AMateria& AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}
AMateria::~AMateria()
{}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout <<  "* does nothing to " << target.getName() << " *" << std::endl;
	
}