#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <sys/time.h>
#include <cstdlib>

Base *generate(void)
{
    timeval time;
    gettimeofday(&time, NULL);
    srand(time.tv_usec);

    int i = rand() % 3;

    if (i == 0)
        return new A();
    if (i == 1)
        return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e)
    {
    }
}

int main()
{  
    Base *base = generate();

    identify(base);
    identify(*base);

    delete base;
    //////////////
    base = generate();

    identify(base);
    identify(*base);

    delete base;
    //////////////
    base = generate();

    identify(base);
    identify(*base);

    delete base;
}