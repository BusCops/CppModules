#ifndef PMERGEME
#define PMERGEME

#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
#include <sys/time.h>
#include <vector>
#include <cmath>
#include <iomanip>

template <template <typename, typename> class Container, typename Value_type>
class PmergeMe
{

  private:
    static int COMPARE_COUNTER;
    int        numOfComparisons;
    double     timeToSort;

    typedef Container<Value_type, std::allocator<Value_type> > container;
    typedef std::pair<Value_type, Value_type>                  pair_type;
    typedef Container<pair_type, std::allocator<pair_type> >   pair_container;

    container main;

    void makePairs(container &nums, pair_container &pairs);
    void mergeInsertSort(container &nums);

  public:
    static bool comp(int a, int b)
    {
        COMPARE_COUNTER++;
        return a < b;
    };

    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    container &sort(std::vector<int> &nums);
    
    int    getComparisionCount();
    double getTimeToSort();
};

std::vector<int>    parseNums(char **av);
std::vector<size_t> jacobsthalOrder(size_t n);

#endif