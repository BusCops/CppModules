#include "PmergeMe.hpp"

int atoi(const std::string &num)
{
    if (num.empty())
        throw std::runtime_error("Error : empty argument");

    if (num[0] == '-')
        throw std::runtime_error("Error : negative number");

    long n = 0;
    for (int i = 0; num[i]; i++)
    {
        if (!isdigit(num[i]))
            throw std::runtime_error("Error : bad input");

        n = (n * 10) + (num[i] - '0');

        if (n > INT_MAX)
            throw std::runtime_error("Error : bad input");
    }
	return n;
}