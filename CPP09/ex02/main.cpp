#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

int main(int ac, char **av)
{
    if (ac >= 3)
    {
        try
        {
            std::vector<int> nums = parseNums(av);

            std::cout << "Before:  ";
            for (size_t i = 0; i < nums.size(); i++)
                std::cout << nums[i] << " ";

            std::cout << std::endl;

            std::vector<int>           sortedNums;
            PmergeMe<std::vector, int> vectorSort;
            PmergeMe<std::deque, int>  dequeSort;

            sortedNums = vectorSort.sort(nums);
            dequeSort.sort(nums);

            std::cout << "After:   ";
            for (size_t i = 0; i < sortedNums.size(); i++)
                std::cout << sortedNums[i] << " ";

            std::cout << std::endl;

            std::cout << std::fixed;

            std::cout << "Time to process a range of " << sortedNums.size()
                      << " elements with std::vector : "
                      << vectorSort.getTimeToSort() << " us" << std::endl;
            std::cout << "Time to process a range of " << sortedNums.size()
                      << " elements with std::deque  : "
                      << dequeSort.getTimeToSort() << " us" << std::endl;

            std::cout << "Number of comparisons:  "
                      << vectorSort.getComparisionCount();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cout << "Usage -> ./PmergeMe 5 2 1 3 (and at least two numbers)"
                  << std::endl;
}
