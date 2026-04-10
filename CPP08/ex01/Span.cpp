#include "Span.hpp"

Span::Span() : maxSize(0), spaceUsed(0), numbers(0)
{
}

Span::Span(unsigned int N) : maxSize(N), spaceUsed(0), numbers()
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		maxSize = other.maxSize;
		spaceUsed = other.spaceUsed;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span()
{
}

