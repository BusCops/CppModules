#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;

	std :: string option;

	std :: cout << "Welcome to PhoneBook" << std :: endl;
	pb.SetIndex(-1);
	while (option != "EXIT")
	{	
		if (std::cin.eof())
            break;
		PrintMsg("enter option \n(1) ADD\n(2) SEARCH\n(3) EXIT");
		if (!getline(std :: cin, option))
			break;
		if (option == "ADD")
			pb.AddContat();
		else if (option == "SEARCH")
			pb.SearchContact();
		else if (option == "EXIT")
			break;
		else
			PrintMsg("Please enter a valid input !");
	}
	std :: cout << "thanks for using our PhoneBook app Goodbye!" << std :: endl;
}
