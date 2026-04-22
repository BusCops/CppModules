#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

class Span
{
  private:
    std::vector<int> numbers;

  public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    long longestSpan();
    long shortestSpan();

    template <typename T> void addNumbers(T begin, T end)
    {

        for (; begin != end; begin++)
        {
            if ((numbers.size()) >= numbers.capacity())
                throw std::runtime_error(
                    "Span is full: cannot add more numbers."
                );
            numbers.push_back(*begin);
        }
    }
};

#endif