#include <iostream>
#include <limits>

#include "tic_tac_toe_game.hpp"

using namespace std;

int main()
{
    cout << "Task 11.4 | Evaluation of the results of the tic-tac-toe game.\n";
    cout << "-----------------------------------------------------------------\n\n";

    string playingField;
    string row;

    cout << "Enter three lines of the playing field:\n";
    cout << "(valid uppercase characters: X O .)\n\n";

    for (size_t i = 0; i < 3; i++)
    {
        getline(cin, row);
        playingField += row;
    }
    cout << "\nResult: ";
    
    if (isTicTacToePlayingFieldCorrect(playingField))
    {
        char result = getResultOfTicTacToeGame(playingField);
        if      (result == 'X') cout << "Petya won\n";
        else if (result == 'O') cout << "Vanya won\n";
        else                    cout << "Nobody\n";
    }
    else
    {
        cout << "Incorrect\n";
    }

    // Prevent console closing.
    cin.clear();
    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    cin.get();
    return 0;
}
