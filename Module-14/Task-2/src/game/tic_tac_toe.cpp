#include "tic_tac_toe.hpp"

#include <iostream>
#include "../console/user_input.hpp"

using namespace std;

void startTicTacToeGame()
{
    char gameBoard[3][3];
    char players[]{'X', 'O'};   // Player marks.
    char winner = 'N';          // X, O - winner. N - no winner.

    initializeBoard(gameBoard);
    drawBoard(gameBoard);

    unsigned position[2];       // The coordinates of the player's last move.

    // The core gameplay loop.
    for (size_t i = 0; i < 9 && winner == 'N'; i++)
    {
        playerTurn(gameBoard, position, players[i % 2]);
        drawBoard (gameBoard);
        winner = checkWinner(gameBoard, position[0], position[1]);
    }

    if (winner != 'N') cout << "Player " << winner << " wins!\n";
    else               cout << "The game is a draw!\n";
}

void initializeBoard(char board[][3])
{
    fill_n(board[0], 3 * 3, ' ');
}

void drawBoard(const char board[][3])
{
    string gameBoard = "\t\t     |     |     \n"
                       "\t\t     |     |     \n"
                       "\t\t_____|_____|_____\n"
                       "\t\t     |     |     \n"
                       "\t\t     |     |     \n"
                       "\t\t_____|_____|_____\n"
                       "\t\t     |     |     \n"
                       "\t\t     |     |     \n"
                       "\t\t     |     |     \n\n";

    for (size_t i = 0, p = 24; i < 3; i++, p += 42)
        for (size_t j = 0; j < 3; j++, p += 6)
            gameBoard[p] = board[i][j];

    cout << '\n' << gameBoard;
}

void playerTurn(char board[][3], unsigned position[2], const char mark)
{
    while (true)
    {
        getPositiveNumericArrayOfUserInput("Player " + string{mark} + " turn.\nEnter row and column number from 1 to 3 (x y): ", position, 2, 1, 3);
        if (putMarkOnBoard(board, mark, (--position[0]), (--position[1])))
            break;
        cout << "Error: This cell is occupied.\n\n";
    }
}

char checkWinner(const char board[][3], const unsigned x, const unsigned y)
{
    char winner = board[x][y];
    bool h  = true;
    bool v  = true;
    bool d1 = true;
    bool d2 = true;

    for (size_t i = 0; i < 3; i++)
    {
        if (board[x][i] != winner) h = false;                       // Row check.
        if (board[i][y] != winner) v = false;                       // Column check.

        if (x != y       || board[i][i]     != winner) d1 = false;  // Check diagonal left to right.
        if ((x + y) != 2 || board[i][2 - i] != winner) d2 = false;  // Check diagonal right to left.

        if (!h && !v && !d1 && !d2)
        {
            winner = 'N';
            break;
        }
    }
    return winner;
}

bool putMarkOnBoard(char board[][3], const char mark, const unsigned x, const unsigned y)
{
    return (board[x][y] == ' ') ? board[x][y] = mark : false;
}
