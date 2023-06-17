#include "tic_tac_toe_game.hpp"

using namespace std;

bool isTicTacToePlayingFieldCorrect(const string field)
{
    if (field.length() != 9)
        return false;

    unsigned int countX   = 0;
    unsigned int countO   = 0;
    unsigned int countDot = 0;
    for (size_t i = 0; i < field.length(); i++)
    {
        if      (field[i] == 'X') countX++;
        else if (field[i] == 'O') countO++;
        else if (field[i] == '.') countDot++;
    }

    // the playing field must contain (X O .) characters
    if ((countX + countO + countDot) != field.length())
        return false;

    if (countX < countO || countX > countO + 1)
        return false;

    if (hasMultipleWinners(field))
        return false;

    if (getResultOfTicTacToeGame(field) == 'X' && countO != countX - 1)
        return false;

    if (getResultOfTicTacToeGame(field) == 'O' && countX != countO)
        return false;

    return true;
}

char getResultOfTicTacToeGame(const string playingField)
{
    string winner;
    for (size_t i = 1; i <= 3; i++)
    {
        winner = getWinnerInString(getRow(playingField, i)) +
                 getWinnerInString(getColumn(playingField, i)) +
                 getWinnerInString(getDiagonal(playingField, i));

        if (!winner.empty())
            return winner[0];
    }
    return 'N';
}

bool hasMultipleWinners(const string field)
{
    string rowWins;
    string columnWins;
    for (size_t i = 1; i <= 3; i++)
    {
        rowWins     += getWinnerInString(getRow(field, i));
        columnWins  += getWinnerInString(getColumn(field, i));
    }

    return (rowWins.length() > 1 || columnWins.length() > 1);
}

string getWinnerInString(const string str)
{
    return (str[0] == str[1] && str[1] == str[2] && str[0] != '.') ? str.substr(0, 1) : "";
}

char getElement(const string field, const size_t x, const size_t y)
{
    return field[x + y * 3];
}

string getRow(const string field, const size_t n)
{
    string row;
    for (size_t i = 0; i < 3; i++)
        row += getElement(field, i, n - 1);

    return row;
}

string getColumn(const string field, const size_t n)
{
    string column;
    for (size_t i = 0; i < 3; i++)
        column += getElement(field, n - 1, i);

    return column;
}

string getDiagonal(const string field, const size_t n)
{
    string diagonal;
    for (size_t i = 0; i < 3; i++)
    {
        if (n == 1) diagonal += getElement(field, i, i);
        else        diagonal += getElement(field, n - i, i);
    }
    return diagonal;
}
