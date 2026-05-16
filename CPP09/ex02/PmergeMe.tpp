#ifndef PERMGEME_TPP
#define PERMGEME_TPP

#include "PmergeMe.hpp"

template <template <typename, typename> class Container, typename Value_type>
int PmergeMe<Container, Value_type>::COMPARE_COUNTER = 0;

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
        main = other.main;
    }
    return *this;
}

template <template <typename, typename> class Container, typename Value_type>
PmergeMe<Container, Value_type>::~PmergeMe()
{
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
        COMPARE_COUNTER++;
    }
}

template <template <typename, typename> class Container, typename Value_type>
void PmergeMe<Container, Value_type>::mergeInsertSort(container &nums)
{
    if (nums.size() <= 1)
        return;

    bool       hasLeftOver = nums.size() % 2 != 0;
    Value_type leftOver    = hasLeftOver ? nums.back() : Value_type();

    pair_container pairs;

    makePairs(nums, pairs);

    container larger;

    for (size_t i = 0; i < pairs.size(); i++)
        larger.push_back(pairs[i].second);

    mergeInsertSort(larger);

    pair_container    sortedPairs;
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < larger.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (!used[j] && pairs[j].second == larger[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    container chain;

    chain.push_back(sortedPairs[0].first);

    for (size_t i = 0; i < sortedPairs.size(); i++)
        chain.push_back(sortedPairs[i].second);

    size_t totalPending = sortedPairs.size() + hasLeftOver;

    std::vector<size_t> order = jacobsthalOrder(totalPending);

    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];

        if (idx == 0)
            continue;

        if (hasLeftOver && idx == totalPending - 1)
        {
            typename container::iterator pos =
                std::lower_bound(chain.begin(), chain.end(), leftOver, comp);
            chain.insert(pos, leftOver);
            continue;
        }

        Value_type value   = sortedPairs[idx].first;
        Value_type pairVal = sortedPairs[idx].second;

        typename container::iterator upperBound =
            std::find(chain.begin(), chain.end(), pairVal);
        typename container::iterator pos =
            std::lower_bound(chain.begin(), upperBound, value, comp);
        chain.insert(pos, value);
    }

    nums = chain;
}

template <template <typename, typename> class Container, typename Value_type>
typename PmergeMe<Container, Value_type>::container &
PmergeMe<Container, Value_type>::sort(std::vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
        main.push_back(nums[i]);

    clock_t start = clock();

    mergeInsertSort(main);

    clock_t end = clock();

    timeToSort = (double(end - start) / CLOCKS_PER_SEC) * 1000000;
    
    numOfComparisons = COMPARE_COUNTER;
    COMPARE_COUNTER  = 0;

    return main;
}

template <template <typename, typename> class Container, typename Value_type>
int PmergeMe<Container, Value_type>::getComparisionCount()
{
    return numOfComparisons;
}

template <template <typename, typename> class Container, typename Value_type>
double PmergeMe<Container, Value_type>::getTimeToSort()
{
    return timeToSort;
}

#endif