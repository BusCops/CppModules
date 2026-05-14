#ifndef ARRAY_T
#define ARRAY_T

#include "PmergeMe.hpp"

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type>::PmergeMe()
{
}

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type>::PmergeMe(
    const PmergeMe<Container, Value_type> &other
)
{
    *this = other;
}

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type> &PmergeMe<Container, Value_type>::operator=(
    const PmergeMe<Container, Value_type> &other
)
{
    if (this != &other)
    {
        main = other.nums;
        // pairs = other.pairs;
    }
    return *this;
}

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type>::~PmergeMe()
{
}

template <template <typename, typename> class Container, typename Value_type>
void PmergeMe<Container, Value_type>::parseNums(char **av)
{
    for (size_t i = 1; av[i]; i++)
    {
        int n = atoi(av[i]);
        main.push_back(n);
    }
}

template <template <typename, typename> class Container, typename Value_type>
void PmergeMe<Container, Value_type>::makePairs(
    container &nums, pair_container &pairs
)
{
    size_t pairsSize = nums.size() / 2;

    for (size_t i = 0; i < pairsSize; i++)
    {
        if (nums[i * 2] > nums[(i * 2) + 1])
            pairs.push_back(std::make_pair(nums[(i * 2) + 1], nums[i * 2]));
        else
            pairs.push_back(std::make_pair(nums[i * 2], nums[(i * 2) + 1]));

    }
}

template <template <typename, typename> class Container, typename Value_type>
typename PmergeMe<Container, Value_type>::container::iterator PmergeMe<Container, Value_type>::binarySearch(typename container::iterator begin,typename container::iterator end,Value_type val)
{
    while (begin < end)
    {
        typename container::iterator mid = begin + (end - begin) / 2;

        if (*mid < val)
            begin = mid + 1;
        else
            end = mid;
    }
    return begin;
}

template <template <typename, typename> class Container, typename Value_type>
void PmergeMe<Container, Value_type>::mergeInsertSort(container &nums)
{
    if (nums.size() <= 1)
        return;

    bool hasLeftOver = nums.size() % 2 != 0;
    Value_type leftOver = hasLeftOver ? nums.back() : Value_type();

    pair_container pairs;

    makePairs(nums, pairs);

    container larger;

    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].second);

    mergeInsertSort(larger);

    pair_container sortedPairs;

    for  (size_t i = 0; i < larger.size();i++)
    {
        for (size_t j = 0;j < pairs.size(); j++)
        {
            if (larger[i] == pairs[j].second)
            {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }

    container chain;

    chain.push_back(sortedPairs[0].first);
    for (size_t i = 0;i < sortedPairs.size();i++)
        chain.push_back(sortedPairs[i].second);

    std::vector<size_t> order = jacobsthalOrder(sortedPairs.size());

    for (size_t i = 0;i < order.size();i++)
    {
        size_t idx = order[i];

        if(idx == 0)
            continue;

        Value_type value = sortedPairs[idx].first;
        typename container::iterator pos = binarySearch(chain.begin(), chain.end(), value);
        chain.insert(pos, value);
    }

    if (hasLeftOver)
    {
        typename container::iterator pos = binarySearch(chain.begin(), chain.end(), leftOver);
        chain.insert(pos, leftOver);
    }

    nums = chain;
}

template <template <typename, typename> class Container, typename Value_type>
void PmergeMe<Container, Value_type>::sort()
{
     std::cout << "befor" << "\n";       
    for(size_t i = 0;i < main.size();i++)
    {
        std::cout << " " << main[i] << " ";
    }
    std::cout << "\n";

    mergeInsertSort(main);
    
    std::cout << "after" << "\n";       
    for(size_t i = 0;i < main.size();i++)
    {
        std::cout << " " << main[i] << " ";
    }
    std::cout << "\n";
}

#endif