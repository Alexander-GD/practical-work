#include "algorithm.hpp"

bool findPairWithGivenSumNotOptimal(const std::vector<int> numbers, const int target, int first[], int second[]) // O(n^2)
{
    for (size_t i = 0; i < numbers.size(); i++) // O(n)
    {
        int currentNumber = target - numbers[i];
        for (size_t j = 0; j < i; j++) // O((n^2 - n) / 2) => O(n^2)
        {
            if (numbers[j] == currentNumber)
            {
                first[0]  = currentNumber;
                second[0] = numbers[i];
                return true;
            }
        }
    }
    return false;
}

bool findPairWithGivenSum(const std::vector<int> numbers, const int target, int first[], int second[]) // O(n)
{
    size_t l = 0;
    size_t r = numbers.size() - 1;

    while (l < r) // O(n - 1) => O(n)
    {
        int sum = numbers[l] + numbers[r];
        if (sum == target)
        {
            first[0]  = numbers[l];
            second[0] = numbers[r];
            return true;
        }
        else if (sum < target)
            l++;
        else
            r--;
    }
    return false;
}
