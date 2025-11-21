#ifndef WrongCat_HPP
#define CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(WrongCat &other);
	~WrongCat();
	WrongCat &operator=(WrongCat &other);
	void makeSound() const;
};

#endif