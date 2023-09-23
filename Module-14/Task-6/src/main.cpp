#include <iostream>

using namespace std;

int main()
{
    cout << "Task 14.6 Snake passage.* (additional task)\n"
         << "----------------------------------------------\n\n";

    int digits[5][5];

    for (size_t i = 0, n = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++, n++)
            digits[i][(2 * (i % 2) - 1) * ((4 * (i % 2)) - j)] = n; // ±1 * (4 * 0/1 - j)

        for (size_t k = 0; k < 5; k++)
            cout << digits[i][k] << ' ';
        cout << '\n';
    }
    cin.get();
    return 0;
}
