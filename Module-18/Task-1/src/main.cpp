#include <iostream>
#include <vector>

using namespace std;

// Swaps element values between arrays.
void swapVec(vector<int>& vec, int* arr)
{
    for (size_t i = 0; i < vec.size(); i++)
        swap(vec[i], arr[i]);
}

int main()
{
    cout << "Task 18.1\n"
         << "------------\n\n";

    vector<int> vec = {1, 2, 3, 4};
    int arr[]       = {2, 4, 6, 8};

    swapVec(vec, arr);

    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i];

    cout << endl;

    for (size_t i = 0; i < vec.size(); i++)
        cout << arr[i];

    cout << endl;

    cin.get();
    return 0;
}
