#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
  private:
    unsigned int     maxSize;
    unsigned int     spaceUsed;
    std::vector<int> numbers;

  public:
    Span();
    Span(unsigned int N);
	Span(const Span &other);
	Span& operator=(const Span &other);
    ~Span();
	
};

#endif