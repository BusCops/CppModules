#include "PmergeMe.hpp"

int ft_atoi(const std::string &num)
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

std::vector<int> parseNums(char **av)
{
    std::vector<int> nums;

    for (size_t i = 1; av[i]; i++)
    {
        int n = ft_atoi(av[i]);
        nums.push_back(n);
    }
    
    return nums;
}

std::vector<size_t> jacobsthalSeq(size_t n)
{
    std::vector<size_t> seq;

    seq.push_back(0);
    seq.push_back(1);

    for (size_t i = 2; seq.back() < n; i++)
        seq.push_back(seq[i - 1] + 2 * seq[i - 2]);
    return seq;
}

std::vector<size_t> jacobsthalOrder(size_t n)
{
    std::vector<size_t> jac = jacobsthalSeq(n);
    std::vector<size_t> order;

    for (size_t i = 2; i < jac.size(); i++)
    {
        size_t current = std::min(jac[i], n) - 1;
        size_t prev    = jac[i - 1];

        for (size_t j = current; j >= prev; j--)
        {
            if (j < n)
                order.push_back(j);
        }
    }
    return order;
}
