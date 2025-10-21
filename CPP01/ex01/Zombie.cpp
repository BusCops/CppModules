#include "Zombie.hpp"

Zombie::~Zombie()
{
	std ::cout << "Zombie Killed !" << std ::endl;
}

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
	: name(name)
{
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}