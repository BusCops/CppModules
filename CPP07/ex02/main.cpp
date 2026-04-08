#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main()
{
    Array<int> a(10);

    for (size_t i = 0; i < a.size(); i++)
    {
        a[i] = i * 10;
    }

    Array<int> b(a);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << b[i] << std::endl;
    }

    try
    {
        b[100];
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}