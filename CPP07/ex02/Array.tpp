#ifndef ARRAY_T
#define ARRAY_T

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
Array<T>::Array() : s(0), array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : s(n)
{
    if (n == 0)
        array = NULL;
    else
        array = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &other) : s(0), array(NULL)
{
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] array;

        s = other.s;
        if (s == 0)
            array = NULL;
        else
        {
            array = new T[s];
            for (size_t i = 0; i < s; i++)
                array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= s)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= s)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return s;
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

#endif