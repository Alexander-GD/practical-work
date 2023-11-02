#include "algorithm.hpp"
#include <iostream>

void PrintArrayInOrderOfModule(const std::vector<int> numbers)
{
    size_t i = 0;
    size_t j = 0;

    while (i != 0 || j < numbers.size()) // O(n)
    {
        if (j != numbers.size() && numbers[j] < 0)
        {
            j++;
            i++;
        }
        else if (i == 0 || (j != numbers.size() && numbers[j] <= abs(numbers[i - 1])))
        {
            std::cout << numbers[j] << ' ';
            j++;
        }
        else
        {
            std::cout << numbers[i - 1] << ' ';
            i--;
        }
    }
    std::cout << std::endl;
}
