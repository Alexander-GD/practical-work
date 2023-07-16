#include "heap_sort.hpp"

using namespace std;

void getUserInputArray(float arr[], const size_t length, string msg);
void printArray(float arr[], const size_t length);
void preventConsoleClosing();

int main()
{
    cout << "Task 12.2 Sorting.\n"; 
    cout << "---------------------\n\n";

    const size_t length = 15;
    float numbers[length];

    getUserInputArray(numbers, length, "Input 15 numbers:\n> ");
    heapSort(numbers, length);  // O(nLogn)
    printArray(numbers, length);

    preventConsoleClosing();
    return 0;
}

void getUserInputArray(float arr[], const size_t length, string msg)
{
    cout << msg;
    for (size_t i = 1; i <= length; i++)
    {
        cin >> arr[i - 1];
        if (cin.fail() || (cin.peek() == '\n' && i < length))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                i--;
            }

            cerr << "\nInput is incorrect! Enter " << (length - i) << " more numbers.\n> ";
            for (size_t j = 1; j <= i; j++)
                cout << arr[j - 1] << " ";
        }
    }
    cin.ignore(INT_MAX, '\n');
}

void printArray(float arr[], const size_t length) {
    cout << '\n';
    for (size_t i = 0; i < length; i++)
        cout << arr[i] << ((i == length - 1) ? "\n" : ", ");
}

void preventConsoleClosing() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cin.get();
}
