#ifndef PMERGEME
#define PMERGEME

#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
#include <vector>

template <template <typename, typename> class Container, typename Value_type>
class PmergeMe
{

  private:
    static int                                                comparCount;
    typedef Container<Value_type, std::allocator<Value_type> > container;
    typedef std::pair<Value_type, Value_type>                 pair_type;
    typedef Container<pair_type, std::allocator<pair_type> >   pair_container;

    container main;

    void makePairs(container &nums, pair_container &pairs);
    void mergeInsertSort(container &nums);
    typename PmergeMe<Container, Value_type>::container::iterator binarySearch(
        typename container::iterator begin,
        typename container::iterator end,
        Value_type                   val
    );

  public:
    static bool comp(int a, int b)
    {
        comparCount++;
        return a < b;
    };

    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void parseNums(char **av);
    void sort();
};

int                 ft_atoi(const std::string &num);
std::vector<size_t> jacobsthalOrder(size_t n);

#endif