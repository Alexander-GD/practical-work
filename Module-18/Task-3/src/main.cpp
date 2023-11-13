#include <iostream>

using namespace std;

// Counts the number of even digits in a number.
void countEvenDigits(const long long number, int &count)
{
    if (number == 0)
        return;

    int lastDigit = number % 10;

    if (lastDigit % 2 == 0)
        count++;

    countEvenDigits(number / 10, count);
}

int main()
{
    cout << "Task 18.3\n"
         << "------------\n\n";

    int evenDigitCount;
    long long number = 9'223'372'036'854'775'806;

    countEvenDigits(number, evenDigitCount);

    cout << "Even numbers: " << evenDigitCount << endl;

    cin.get();
    return 0;
}
