#include "Span.hpp"

Span::Span() : numbers()
{
    numbers.reserve(0);
}

Span::Span(unsigned int N) : numbers()
{
    numbers.reserve(N);
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
        numbers = other.numbers;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (numbers.size() >= numbers.capacity())
        throw std::runtime_error("Span is full: cannot add more numbers.");
    else
        numbers.push_back(n);
}

long Span::longestSpan()
{
    long maxValue;
    long minValue;
    if (numbers.size() <= 1)
        throw std::runtime_error(
            "Not enough elements to compute span (minimum 2 required)."
        );
    maxValue = *std::max_element(numbers.begin(), numbers.end());
    minValue = *std::min_element(numbers.begin(), numbers.end());
    return maxValue - minValue;
}

long Span::shortestSpan()
{
    if (numbers.size() <= 1)
        throw std::runtime_error(
            "Not enough elements to compute span (minimum 2 required)."
        );
    std::sort(numbers.begin(), numbers.end());
    long tmp;
    long min = (long)numbers[1] - (long)numbers[0];
    for (size_t i = 0; i < numbers.size() - 1; i++)
    {
        tmp = (long)numbers[i + 1] - (long)numbers[i];
        if (tmp < min)
            min = tmp;
    }
    return min;
}
