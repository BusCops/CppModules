#include "iter.hpp"
#include <iostream>
#include <cstring>
#include <stdlib.h>

void toLowerChar(char &c)
{
    c = std::tolower(c);
}

void toUpperChar(char &c)
{
    c = std::toupper(c);
}

void incrementInt(int &i)
{
    i++;
}

void decrementInt(int &i)
{
    i--;
}

void printInt(const int &x)
{
    std::cout << x << " ";
}

template <typename T>
void printAny(const T &x)
{
    std::cout << x << " ";
}

int main()
{
    char *str1 = strdup("toupper");
    char *str2 = strdup("TOLOWER");

    iter(str1, 8, toUpperChar);
    iter(str2, 7, toLowerChar);
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};

    iter(arr, 5, incrementInt);
    std::cout << "After incrementing: \n";
    iter(arr, 5, printInt);
    std::cout << std::endl;

    iter(arr, 5, decrementInt);
    std::cout << "After decrementing: \n";
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::cout << "print const array: \n";
    iter(arr2, 5, printInt);
    std::cout << std::endl;

    std::cout << "print const array with template printAny: \n";
    iter(arr2, 5, printAny<int>);
    std::cout << std::endl;

    free(str1);
    free(str2);
}