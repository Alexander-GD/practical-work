#include <iostream>

using namespace std;

// Calculates the number of unique ways the rabbit can reach the top of the ladder.
int countWays(const int ladderSize, const int maxJumpSize = 3)
{
    if (ladderSize < 0)
        return 0;

    if (ladderSize == 0)
        return 1;

    int ways = 0;
    for (int i = 1; ((i <= maxJumpSize) && (ladderSize - i >= 0)); i++)
        ways += countWays(ladderSize - i, maxJumpSize);

    return ways;
}

int main()
{
    cout << "Task 18.2\n"
         << "------------\n\n";

    cout << "Number of ways: " << countWays(6) << endl;

    cin.get();
    return 0;
}
