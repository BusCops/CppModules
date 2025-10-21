#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string file = av[1];
		std::string string1 = av[2];
		std::string string2 = av[3];
		if (file.empty() | string1.empty())
		{
			std::cout << "file or string 1 cant be empty" << std::endl;
			return 0;
		}
		Replace rep(string1, string2, file);
		rep.ReplaceStrings();
	}
	else
		std::cout << "programe input are :\n-> <filename>\n-> string1\n-> string2" << std::endl;
}
