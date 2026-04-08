#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
    unsigned int s;
    T *array;

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &other);
    ~Array();
    Array<T>& operator=(const Array<T> &other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};

#endif