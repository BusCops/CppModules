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

class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
private:
	AMateria *Source[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif