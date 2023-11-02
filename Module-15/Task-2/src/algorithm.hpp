#pragma once
#include <vector>

/**
 * @brief Find two numbers in array whose sum equals the given value.
 *        Time complexity is O(n^2).
 *        Space complexity is O(1).
 * @param numbers Array of numbers.
 * @param target  The sum of two array elements.
 * @param first   The first number found.
 * @param second  The second number found.
 * @return True if the array contains two numbers whose sum equals the given value, otherwise false.
 */
bool findPairWithGivenSumNotOptimal(const std::vector<int> numbers, const int target, int first[], int second[]);

/**
 * @brief Find two numbers in array whose sum equals the given value.
 *        The passed array must be sorted in ascending order!
 *        Time complexity is O(n).
 *        Space complexity is O(1).
 * @param numbers Array of numbers.
 * @param target  The sum of two array elements.
 * @param first   The first number found.
 * @param second  The second number found.
 * @return True if the array contains two numbers whose sum equals the given value, otherwise false.
 */
bool findPairWithGivenSum(const std::vector<int> numbers, const int target, int first[], int second[]);
