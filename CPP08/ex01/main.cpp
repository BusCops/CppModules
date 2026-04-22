#include "Span.hpp"
#include <limits.h>

void minMaxTest()
{
    try
    {
        Span sp = Span(2);
        sp.addNumber(INT_MIN);
        sp.addNumber(INT_MAX);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void subjectTest()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void spanFulltest()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void notEnoughElementTest()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void addContainerNumberTest()
{
    try
    {
        std::list<int> l;
        l.push_back(11);
        l.push_back(3);
        l.push_back(2);
        l.push_back(9);

        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumbers(l.begin(), l.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void moreNumbersTest()
{
    try
    {
        Span sp(10000);

        std::vector<int> v;

        for (int i = 0; i < 10000; i++)
            v.push_back(i);

        sp.addNumbers(v.begin(), v.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "-----------------------test1-----------------------"
              << std::endl;
    minMaxTest();
    std::cout << "-----------------------test2-----------------------"
              << std::endl;
    subjectTest();
    std::cout << "-----------------------test3-----------------------"
              << std::endl;
    spanFulltest();
    std::cout << "-----------------------test4-----------------------"
              << std::endl;
    notEnoughElementTest();
    std::cout << "-----------------------test5-----------------------"
              << std::endl;
    addContainerNumberTest();
    std::cout << "-----------------------test6-----------------------"
              << std::endl;
    moreNumbersTest();
}