#include <iostream>
#include <vector>

#include "console/user_input.hpp"

using namespace std;

int main()
{
    cout << "Task 13.3* (additional task)\n";
    cout << "-------------------------------\n\n";

    vector<int> storage(20);
    size_t realSize = 0;
    size_t head = 0;

    while (true)
    {
        int input = getNumericUserInput("Enter number: ");

        if (input == -1)
        {
            cout << "Storage: ";
            for (size_t i = 0, j = head; i < realSize; i++, j++)
            {
                if (j == realSize) j = 0;
                cout << storage[j] << " ";
            }
            cout << '\n';
        }
        else
        {
            if (realSize <= head) realSize++;
            storage[head] = input;
            ++head %= storage.size();
        }
    }

    preventConsoleClosing();
    return 0;
}
