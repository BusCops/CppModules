#include <iostream>

int main(int ac, char **av)
{
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			av[i][j] = std :: toupper(av[i][j]);
		std :: cout << av[i];
	}
	if (ac == 1)
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
	std :: cout << std :: endl;
}