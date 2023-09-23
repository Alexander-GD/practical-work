#pragma once

#include <string>

using uint = unsigned;

/**
 * @brief Launch the game "Battleship".
 */
void startBattleshipGame();

/**
 * @brief Fills two game boards with the starting marks of the sea.
 * @param boards The game boards 10x10.
 * @param mark   The mark of the sea.
 */
void initializeBoards(char boards[][10][10], const char mark);

/**
 * @brief Fills the array of ship coordinates with the initial value 10.
 * @param locationOfShips An array containing the location of the ships.
 */
void initializeShipCoordinates(uint locationOfShips[][10][2][2]);

/**
 * @brief Placement of ships on the game board.
 * @param boards          The game boards 10x10.
 * @param marks           The game marks.
 * @param playerNames     An array containing the player of the names.
 * @param numberOfShips   An array containing the number of the ships.
 * @param nameOfShips     An array containing the names of the ships.
 * @param locationOfShips An array containing the location of the ships.
 * @param playerId        The player ID.
 */
void placementOfShips(char boards[][10][10], const char marks[], const std::string playerNames[], uint numberOfShips[][4], const std::string nameOfShips[], uint locationOfShips[][10][2][2], const uint playerId);

/**
 * @brief Receives shot coordinates from the player and places a marker on the game board.
 * @param board    The game board 10x10.
 * @param marks    The game marks.
 * @param playerId The player ID.
 * @param shot     Coordinates of the shot.
 * @return The result of a shot: 0 - miss, 1 - hit, -1 - this square has already been shot.
 */
int takeShot(char board[][10][10], const char marks[], const uint playerId, uint shot[]);

/**
 * @brief The player ID.
 * @param numberOfShips An array containing the number of the ships.
 * @return The ID of the player who has ships left on the game board.
 */
uint getWinnerId(const uint numberOfShips[][4]);

/**
 * @brief Places a ship on the game board at the given coordinates.
 * @param board    The game board 10x10.
 * @param location The ship location coordinates.
 * @param mark     The mark of the ship.
 * @param playerId The player ID.
 */
void placeShipOnBoard(char board[][10][10], const uint location[][2], const char mark, const uint playerId);

/**
 * @brief Places miss markers around a sunken ship.
 * @param board           The game board 10x10.
 * @param locationOfShips An array containing the location of the ships.
 * @param mark            The mark of the miss.
 * @param shipId          Index/id of the ship in the array of ship locations.
 * @param playerId        The player ID.
 */
void placeMarksOnBoardAroundShip(char board[][10][10], const uint locationOfShips[][10][2][2], const char mark, const uint shipId, const uint playerId);

/**
 * @brief Get the ship's index/id in the array of ship locations at the given coordinates.
 * @param locationOfShips An array containing the location of the ships.
 * @param x               Coordinate of the ship.
 * @param y               Coordinate of the ship.
 * @param playerId        The player ID.
 * @return The index/id of a ship in an array of ship locations.
 */
uint getShipId(const uint locationOfShips[][10][2][2], const uint x, const uint y, const uint playerId);

/**
 * @brief Get the ship type based on the given ship coordinates.
 * @param location The ship location coordinates.
 * @return The type of ship (i.e. number of decks).
 */
uint getTypeShip(const uint location[][2]);

/**
 * @brief Get number of ships.
 * @param numberOfShips An array containing the number of the ships.
 * @param playerId      The player ID.
 * @return The number of ships.
 */
uint getNumberOfShips(const uint numberOfShips[][4], const uint playerId);

/**
 * @brief Get the coordinates of the area around the ship.
 * @param ship The ship location coordinates.
 * @param area Coordinates of the area around the ship.
 */
void getAreaAroundShip(const uint ship[][2], uint area[][2]);

/**
 * @brief Requests player names from the user.
 * @param playerNames An array containing the player of the names.
 */
void getPlayerNamesFromUser(std::string playerNames[]);

/**
 * @brief Requests the ship's location coordinates from the user.
 * @param board    The game board 10x10.
 * @param mark     The mark of the ship.
 * @param type     The type of ship (i.e. number of decks).
 * @param playerId The player ID.
 * @param location Ship location coordinates specified by the user.
 */
void getShipLocationFromUser(const char board[][10][10], const char mark, const uint type, const uint playerId, uint location[][2]);

/**
 * @brief Are the ship's location coordinates valid.
 * @param location The ship location coordinates.
 * @return True if the coordinates are valid, false otherwise.
 */
bool isCoordinatesValid(const uint location[][2]);

/**
 * @brief Is the ship located diagonally.
 * @param location The ship location coordinates.
 * @return True if the ship is located diagonally, false otherwise.
 */
bool isShipLocatedDiagonally(const uint location[][2]);

/**
 * @brief Does the ship intersect with another ship on the game board.
 * @param board    The game board 10x10.
 * @param mark     The mark of the ship.
 * @param location The ship location coordinates.
 * @param playerId The player ID.
 * @return True if the ship intersect another ship, false otherwise.
 */
bool isShipsIntersect(const char board[][10][10], const char mark, const uint location[][2], const uint playerId);

/**
 * @brief Is the ship located close to another ship.
 * @param board    The game board 10x10.
 * @param mark     The mark of the ship.
 * @param location The ship location coordinates.
 * @param playerId The player ID.
 * @return True if the ship is located close to another ship, false otherwise.
 */
bool isShipsTouch(const char board[][10][10], const char mark, const uint location[][2], const uint playerId);

/**
 * @brief Is the ship sunk.
 * @param board           The game board 10x10.
 * @param locationOfShips An array containing the location of the ships.
 * @param shipId          Index/id of the ship in the array of ship locations.
 * @param playerId        The player ID.
 * @return True if the ship sank, false otherwise.
 */
bool isShipSunk(const char board[][10][10], const uint locationOfShips[][10][2][2], const uint shipId, const uint playerId);

/**
 * @brief Is there a winner.
 * @param numberOfShips An array containing the number of the ships.
 * @return true if there is a winner, false otherwise.
 */
bool hasWinner(const uint numberOfShips[][4]);

/**
 * @brief Prints the splash screen.
 */
void printSplashScreen();

/**
 * @brief Print player's turn.
 * @param player Player name.
 */
void printPlayerTurn(const std::string player);

/**
 * @brief Print game boards for both players.
 * @param boards   The game boards 10x10.
 * @param marks    The game marks.
 * @param playerId The player ID.
 */
void printBoards(const char boards[][10][10], const char marks[], const uint playerId);

/**
 * @brief Print stats of both players.
 * @param nameOfShips   An array containing the names of the ships.
 * @param numberOfShips An array containing the number of the ships.
 * @param playerNames   An array containing the player of the names.
 * @param playerId      The player ID.
 */
void printStatistics(const std::string nameOfShips[], const uint numberOfShips[][4], const std::string playerNames[], const uint playerId);

/**
 * @brief Print the end of the game and the name of the winner.
 * @param winner Name of the winner.
 */
void printGameEnd(const std::string winner);

/**
 * @brief Clears the console and then prints the game boards and statistics for both players.
 * @param boards        The game boards 10x10.
 * @param marks         The game marks.
 * @param numberOfShips An array containing the number of the ships.
 * @param nameOfShips   An array containing the names of the ships.
 * @param playerNames   An array containing the player of the names.
 * @param playerId      The player ID.
 */
void updateInterface(const char boards[][10][10], const char marks[], const uint numberOfShips[][4], const std::string nameOfShips[], const std::string playerNames[], const uint playerId);

/**
 * @brief Clear the interface in the console.
 */
void clearInterface();
