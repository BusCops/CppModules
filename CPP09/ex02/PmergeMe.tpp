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

    std::cout << "----------------------------------------------------------" << std::endl;
    for (size_t i = 0; i < pairs.size(); i++)
        std::cout << pairs[i].first << " and " << pairs[i].second << std::endl;
}

template <template <typename, typename> class Container, typename Value_type>
void PmergeMe<Container, Value_type>::mergeInsertSort(container &nums)
{
    if (nums.size() <= 1)
        return;

    pair_container pairs;

    makePairs(nums, pairs);

    container larger;
    container smaller;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        larger.push_back(pairs[i].second);
        smaller.push_back(pairs[i].first);
    }
    mergeInsertSort(larger);
}

template <template <typename, typename> class Container, typename Value_type>
void PmergeMe<Container, Value_type>::sort()
{
    mergeInsertSort(main);
}

#endif