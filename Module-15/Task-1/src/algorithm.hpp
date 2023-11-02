#pragma once
#include <vector>

/**
 * @brief Find the greatest sum of consecutive elements in the array.
 *        Time complexity is O(n^3).
 *        Space complexity is O(1).
 * @param numbers Array of numbers.
 * @param begin   Range start index.
 * @param end     Range end index.
 * @return The largest amount of consecutive elements and the index of the
 *         beginning and the end of the range of this sequence.
 */
int maxSubarraySumNotOptimal(const std::vector<int> numbers, size_t begin[], size_t end[]);

/**
 * @brief Find the greatest sum of consecutive elements in the array.
 *        The Kadane algorithm is used.
 *        Time complexity is O(n).
 *        Space complexity is O(1).
 * @param numbers Array of numbers.
 * @param begin   Range start index.
 * @param end     Range end index.
 * @return The largest amount of consecutive elements and the index of the
 *         beginning and the end of the range of this sequence.
 */
int maxSubarraySum(const std::vector<int> numbers, size_t begin[], size_t end[]);
