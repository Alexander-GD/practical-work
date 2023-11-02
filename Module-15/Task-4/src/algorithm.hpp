#pragma once
#include <vector>

/**
 * @brief Prints the array to the console as an array sorted by modulus of numbers in ascending order.
 *        The passed array must be sorted in ascending order!
 *        Time complexity is O(n).
 *        Space complexity is O(1).
 * @param numbers Array sorted in ascending order.
 */
void PrintArrayInOrderOfModule(const std::vector<int> numbers);
