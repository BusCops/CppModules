#ifndef ARRAY_T
#define ARRAY_T

#include <cstddef>

template <typename T>
Array<T>::Array() : size(0), array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : size(n), array(new T[size])
{
}

#endif