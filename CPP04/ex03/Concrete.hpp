#ifndef CONCRETE_HPP
#define CONCRETE_HPP

class AMateria;
class ICharacter;

class Ice : public AMateria
{
public :
	Ice();
	Ice(const Ice &other);
	Ice& operator=(const Ice &other);
	~Ice();
	Ice* clone() const;
	void use(ICharacter& target);
};

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	Cure& operator=(const Cure &other);
	~Cure();
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif