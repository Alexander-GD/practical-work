#include <iostream>
#include <vector>

#include "console/user_input.hpp"

using namespace std;

void printArray(vector<int> arr);

int main()
{
    cout << "Task 13.1\n";
    cout << "------------\n\n";

    unsigned vecSize = getPositiveNumericUserInput("Enter vector size: ");

    vector<int> numbers(vecSize);

    numbers    = getNumericSequenceOfUserInput("\nEnter " + to_string(vecSize) + " numbers: ", vecSize);
    int number = getNumericUserInput("\nEnter number to delete: ");

    unsigned deletion = 0;
    for (size_t i = 0, j = 0; i < vecSize; i++)
    {
        if (numbers[i] != number)
        {
            numbers[j] = numbers[i];
            j++;
        }
        else
            deletion++;
    }

    while (deletion--)
        numbers.pop_back();

    cout << "\nResult: ";
    printArray(numbers);

    preventConsoleClosing();
    return 0;
}

void printArray(vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
