#include "AMateria.hpp"
#include "Concrete.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	(void)other;
	*this = other;
}
Ice& Ice::operator=(const Ice &other)
{
	(void)other;
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

Cure::Cure(const Cure &other) : AMateria("cure")
{
	*this = other;
}

Cure& Cure::operator=(const Cure &other)
{
	(void)other;
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

///////////////////////////////////////////////////////////////////////////////////

void	InistializeSource(AMateria **Source)
{
	for (int i = 0; i < 4;i++)
		Source[i] = NULL;
}

MateriaSource::MateriaSource()
{
	InistializeSource(Source);
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	InistializeSource(Source);
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0;i < 4;i++)
		{
			if (Source[i])
				delete Source[i];
			Source[i] = NULL;
		}

		for (int i = 0;i < 4;i++)
		{
			if (other.Source[i])
				Source[i] = other.Source[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for( int i = 0;i < 4;i++)
	{
		if (Source[i])
			delete Source[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	int i = 0;
	for(i = 0;i < 4 && Source[i] != NULL;i++)
	{}
	if (i < 4)
		Source[i] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0;i < 4;i++)
	{
		if (type == Source[i]->getType())
			return Source[i]->clone();
	}
	return NULL;
}