#pragma once

/**
 * @brief The function starts the game of Tic-Tac-Toe.
 */
void startTicTacToeGame();

/**
 * @brief Fills the game board with initial values.
 * @param board Game board.
 */
void initializeBoard(char board[][3]);

/**
 * @brief Display the game board in the console.
 * @param board Game board.
 */
void drawBoard(const char board[][3]);

/**
 * @brief Request the player the coordinates of the next move.
 *        Then put a mark on the game board using new coordinates.
 *        Until the player enters valid coordinates, an error message will be displayed.
 * @param board    Game board.
 * @param position The coordinates of the player's current turn.
 * @param mark     The mark that is placed on the game board.
 */
void playerTurn(char board[][3], unsigned position[2], const char mark);

/**
 * @brief Checks if there is a winner based on the location of the mark.
 * @param board Game board.
 * @param x     Mark coordinate.
 * @param y     Mark coordinate.
 * @return 'X' or 'O' depending on the winner. Will return 'N' if no winner is found.
 */
char checkWinner(const char board[][3], const unsigned x, const unsigned y);

/**
 * @brief Put the mark on the game board.
 * @param board Game board.
 * @param mark  The mark.
 * @param x     Mark coordinate.
 * @param y     Mark coordinate.
 * @return True if the placement is successful, false otherwise.
 */
bool putMarkOnBoard(char board[][3], const char mark, const unsigned x, const unsigned y);
