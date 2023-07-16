#include <iostream>

using namespace std;

void preventConsoleClosing();

int main()
{
    cout << "Task 12.4 A series of numbers.* (additional task).\n";
    cout << "-----------------------------------------------------\n\n";

    const int length = 15;
    int numbers[length] = {501, 505, 504, 503, 511, 507, 508, 509, 510, 500, 512, 506, 502, 511, 513};  // X = 500, repeated = 511

    int sumOfNumbers = 0;
    int minNumber = numbers[0];
    for (size_t i = 0; i < length; i++)  // O(n)
    {
        sumOfNumbers += numbers[i];
        if (minNumber > numbers[i])
            minNumber = numbers[i];
    }

    int sumOfSequence  = (minNumber + (minNumber + length - 2)) * (length - 1) / 2;  // using the Gaussian method
    int repeatedNumber = sumOfNumbers - sumOfSequence;

    cout << "Repeating number is " << repeatedNumber << '\n';

    preventConsoleClosing();
    return 0;
}

void preventConsoleClosing()
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cin.get();
}
