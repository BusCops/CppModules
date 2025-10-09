#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

bool	PrintMsg(std :: string msg);

class PhoneBook
{
	private :
		Contact contact[8];
		int		index;
	public :
		void	UpdateIndex();
		void	SetIndex(int i);
		void	AddContat();
		void	SearchContact();
};

#endif