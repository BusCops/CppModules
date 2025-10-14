#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>



class Zombie
{
	private :
		std :: string name;
	public :
		void	announce(void);
		void	SetZombieName(std :: string Name);
	~Zombie();
};

Zombie*	zombieHorde(int N, std :: string name);

#endif