#include "RPN.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac == 2)
    {
        try
        {
			RPN calculator;

			calculator.calculate(av[1]);
        }
        catch (std::exception &e)
        {
			std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Exemple of how to use => ./RPN \"5 5 * 6 - 1 +\""
                  << std::endl;
}