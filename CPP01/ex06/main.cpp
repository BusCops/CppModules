#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac == 2)
	{
		std::string level = av[1];
		std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		int i = 0;
		while (levels[i] != level && i < 4)
			i++;
		switch (i)
		{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	return 0;
}
