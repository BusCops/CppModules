#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T *array, size_t lenght, void (*f)(F &))
{
    for (size_t i = 0; i < lenght ; i++)
        f(array[i]);
}

template <typename T, typename F>
void iter(const T *array, size_t lenght, void (*f)(F const &))
{
    for (size_t i = 0; i < lenght ; i++)
        f(array[i]);
}

#endif