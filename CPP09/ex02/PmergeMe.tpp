#ifndef ARRAY_T
#define ARRAY_T

#include "PmergeMe.hpp"

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type>::PmergeMe()
{
}

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type>::PmergeMe(
    const PmergeMe<Container, Value_type> &other
)
{
    *this = other;
}

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type> &PmergeMe<Container, Value_type>::operator=(
    const PmergeMe<Container, Value_type> &other
)
{
    if (this != &other)
    {
        pairs = other.pairs;
    }
    return *this;
}

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type>::~PmergeMe()
{
}

#endif