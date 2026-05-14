#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

int main(int ac, char **av)
{
    if (ac >= 3)
    {
        PmergeMe<std::deque, int> obj;
        try
        {
            obj.parseNums(av);
            obj.sort();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout << "Usage -> ./PmergeMe 5 2 1 3 (and at least two numbers)"
                  << std::endl;
}
