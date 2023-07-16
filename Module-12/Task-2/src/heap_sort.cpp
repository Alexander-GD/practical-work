#include "heap_sort.hpp"

void buildHeap(float arr[], const size_t length)            // O(nLogn)
{
    for (size_t parentNode = (length >> 1); parentNode--;)  // O(n/2) -> O(n)
        minHeapify(arr, length, parentNode);                // O(Logn)
}

void minHeapify(float heap[], const size_t size, const size_t parent) // O(Logn) worst case
{                                                                     // O(1) best case
    if (size == 1)
        return;

    size_t smallest = parent;       // the node with the smallest value
    size_t left  = 2 * parent + 1;  // the left child node
    size_t right = left + 1;        // the right child node

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    // swap values if the parent is larger than the child node
    if (smallest != parent)
    {
        std::swap(heap[parent], heap[smallest]);

        // if the node is a non-leaf, recursively call the heapify function on that sub-tree
        if (smallest < (size >> 1))
            minHeapify(heap, size, smallest);
    }
}

void heapSort(float arr[], const size_t length) // O(nLogn + n * Logn) -> O(nLogn)
{
    buildHeap(arr, length);                     // O(nLogn)
    for (size_t i = length - 1; i > 0; i--)     // O(n)
    {
        std::swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);                  // O(Logn) 
    }
}
