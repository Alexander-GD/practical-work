#pragma once

#include <iostream>

/**
 * @brief  Build a heap data structure from the given array.
 * @param arr     Array to build the heap.
 * @param length  The array length.
 * @return  The built heap will be stored in the passed array.
 */
void buildHeap(float arr[], const size_t length);

/**
 * @brief  Rearranges the sub-tree nodes according to the min heap property.
 * @param heap    The heap data structure.
 * @param size    The heap size.
 * @param parent  The index of parent node in sub-tree.
 */
void minHeapify(float heap[], const size_t size, const size_t parent);

/**
 * @brief  Sorts an array in descending order using the heapsort algorithm.
 * @param arr     The array to sort.
 * @param length  The array length.
 */
void heapSort(float arr[], const size_t length);
