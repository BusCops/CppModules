#include "Replace.hpp"

int main(int ac, char **av)
{
	std::string file = av[1];
	std::string string1 = av[2];
	std::string string2 = av[3];
	if (ac == 4)
	{
		Replace rep(string1, string2, file);
		rep.ReplaceStrings();
	}
	else
		std::cout << "programe input are :\n-> <filename>\n-> string1\n-> string2" << std::endl;
}
