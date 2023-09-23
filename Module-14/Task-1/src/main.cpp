#include <iostream>

using namespace std;

int main()
{
    cout << "Task 14.1 Banquet table.\n"
         << "---------------------------\n\n";

    unsigned cutlery[2][6] = {{4, 4, 3, 3, 3, 3}, {3, 3, 3, 3, 3, 3}};
    unsigned dishes [2][6] = {{3, 3, 2, 2, 2, 2}, {2, 2, 2, 2, 2, 2}};
    unsigned chairs [2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

    // Add one chair, since the lady brought her child with her.
    chairs[0][4]  += 1;

    // Spoon stolen.
    cutlery[1][2] += 1;

    // A VIP shared her spoon with someone who was left without a spoon.
    cutlery[0][0] -= 1;
    cutlery[1][2] += 1;

    // The waiter took one dessert plate from the VIP guest.
    dishes[0][0]  -= 1;

    cin.get();
    return 0;
}
