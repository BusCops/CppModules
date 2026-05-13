#ifndef PMERGEME
#define PMERGEME

#include <deque>
#include <iostream>
#include <vector>

template <template <typename, typename> class Container, typename Value_type>
class PmergeMe
{
  private:
    typedef Container<Value_type, std::allocator<Value_type> > container;

    typedef std::pair<Value_type, Value_type> pair_type;

    typedef Container<pair_type, std::allocator<pair_type> > pair_container;

    container      data;
    pair_container pairs;

  public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
};

#endif