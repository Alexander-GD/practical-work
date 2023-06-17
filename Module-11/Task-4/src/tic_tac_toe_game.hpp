#pragma once

#include <string>

/**
 * @brief  Check if the Tic-Tac-Toe playing field is correct.
 * @param field  The playing field.
 */
bool isTicTacToePlayingFieldCorrect(const std::string field);

/**
 * @brief  Get the result of the Tic-Tac-Toe game.
 * @param playingField  The playing field.
 * @return  'X' - if the crosses won, 'O' - if the zeros won,
 *          'N' - if the game is not over or a tie.
 */
char getResultOfTicTacToeGame(const std::string playingField);

/**
 * @brief  Check if there are more than one winner.
 * @param field  The playing field.
 */
bool hasMultipleWinners(const std::string field);

/**
 * @brief  Get the winner in string.
 * @param str  The string containing the game symbols (e.g. "X . O").
 * @return  "X" - if the crosses won, "O" - if the zeros won, otherwise empty string
 */
std::string getWinnerInString(const std::string str);

/**
 * @brief Get playfield element.
 * @param field  The playing field.
 * @param x  Element coordinate.
 * @param y  Element coordinate.
 * @return  The character of the playing field.
 */
char getElement(const std::string field, const size_t x, const size_t y);

/**
 * @brief  Get the row from the playing field.
 * @param field  The playing field.
 * @param n      The row number.
 * @return  Ther string containing a row of the playing field.
 */
std::string getRow(const std::string field, const size_t n);

/**
 * @brief  Get the column from the playing field.
 * @param field  The playing field.
 * @param n      The column number.
 * @return  Ther string containing a column of the playing field.
 */
std::string getColumn(const std::string field, const size_t n);

/**
 * @brief  Get the diagonal from the playing field.
 * @param field  The playing field.
 * @param n      The diagonal number.
 * @return  Ther string containing a diagonal of the playing field.
 */
std::string getDiagonal(const std::string field, const size_t n);
