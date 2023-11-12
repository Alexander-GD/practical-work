#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, const size_t size) // O(n)
{
    for (size_t i = 0; i < (size / 2); i++) // O(n/2)
        swap((arr + i), (arr + size - i - 1));
}

int main()
{
    cout << "Task 17.2\n"
         << "------------\n\n";


    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverse(arr, size(arr));

    for (size_t i = 0; i < size(arr); i++)
        cout << *(arr + i) << " ";

    cin.get();
    return 0;
}
