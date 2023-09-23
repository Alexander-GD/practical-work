#include <iostream>
#include <vector>

#include "console/user_input.hpp"
#include "game/battleship.hpp"

using namespace std;

int main()
{
    cout << "Task 14.8 Battleship.* (additional task)\n"
            "-------------------------------------------\n";

    startBattleshipGame();

    preventConsoleClosing();
    return 0;
}
