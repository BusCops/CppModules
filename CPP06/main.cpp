#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string value = av[1];
        ScalarConverter::convert(value);
		
    }
    return 0;
}