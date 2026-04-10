#include "easyfind.hpp"

int main()
{
    std::vector<int> integers;
    integers.push_back(6);
    integers.push_back(1);
    integers.push_back(11);
    integers.push_back(156);
    integers.push_back(2);
    integers.push_back(3);

    try
    {
        std::vector<int>::iterator it = easyfind(integers, 5);
        std::cout << "Number found ->" << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(integers, 156);
        std::cout << "Number found ->" << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(integers, 1);
        std::cout << "Number found ->" << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}