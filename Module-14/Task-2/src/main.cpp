#include <iostream>

#include "console/user_input.hpp"
#include "game/tic_tac_toe.hpp"

using namespace std;

int main()
{
    cout << "Task 14.2 Tic-Tac-Toe.\n"
         << "-------------------------\n\n";

    startTicTacToeGame();

    preventConsoleClosing();
    return 0;
}
