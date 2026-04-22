#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

template <typename Container>
typename Container::iterator easyfind(Container &c, int i)
{
    typename Container::iterator it = std::find(c.begin(), c.end(), i);
    if (it == c.end())
        throw(std::runtime_error("Number Not Found !"));
    return it;
}

#endif