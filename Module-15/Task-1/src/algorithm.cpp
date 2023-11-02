#include "algorithm.hpp"

int maxSubarraySumNotOptimal(const std::vector<int> numbers, size_t begin[], size_t end[]) // O(n^3)
{
    int maxSum = (numbers.size() != 0) ? numbers[0] : 0;
    begin[0] = 0;
    end[0]   = 0;

    for (size_t i = 0; i < numbers.size(); i++) // O(n)
    {
        for (size_t j = numbers.size() - 1; j > i; j--) // O((n^2 - n) / 2) => O(n^2)
        {
            int sum = 0;
            for (size_t k = i; k <= j; k++) // O((n^3 + 3n^2 - 4n) / 6) => O(n^3)
                sum += numbers[k];

            if (sum > maxSum || (i == 0 && j == numbers.size() - 1))
            {
                maxSum   = sum;
                begin[0] = i;
                end[0]   = j;
            };
        }
    }
    return maxSum;
}

int maxSubarraySum(const std::vector<int> numbers, size_t begin[], size_t end[]) // O(n)
{
    int maxSum = (numbers.size() != 0) ? numbers[0] : 0;
    begin[0] = 0;
    end[0]   = 0;

    int    sum    = maxSum;
    int    minSum = 0;
    size_t minPos = 0;

    for (size_t i = 1; i < numbers.size(); i++) // O(n-1) => O(n)
    {
        sum += numbers[i];

        if ((sum - minSum > maxSum) || (i == 1))
        {
            maxSum   = sum - minSum;
            begin[0] = minPos;
            end[0]   = i;
        }

        if (sum - numbers[i] < minSum)
        {
            minSum = sum - numbers[i];
            minPos = i;
        }
    }
    return maxSum;
}
