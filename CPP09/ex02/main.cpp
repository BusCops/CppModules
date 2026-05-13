#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac == 2)
    {
        PmergeMe<std::vector, int>  obj;
        std::vector<int>                                             v;

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        v.push_back(7);
        v.push_back(8);
    }
    else
        std::cout << "Error : ." << std::endl;
}