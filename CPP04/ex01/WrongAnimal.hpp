#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal &other);
	~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal &other);
	std::string getType() const;
	void makeSound() const;
};

#endif