#include "battleship.hpp"

#include <iostream>
#include <iomanip>

#include "../console/user_input.hpp"
#include "../console/commands.hpp"

using namespace std;

void startBattleshipGame()
{
    string playerNames[2]{};
    char   boards[2][10][10]{};
    char   marks[]{'O', 'x', '.', '~'};
    uint   numberOfShips[2][4]{};
    uint   locationOfShips[2][10][2][2]{};
    string nameOfShips[]{"Patrol Boat", "Submarine", "Battleship", "Carrier"};

    printSplashScreen();
    initializeBoards(boards, marks[3]);
    initializeShipCoordinates(locationOfShips);
    getPlayerNamesFromUser(playerNames);

    // Placement of ships on the game board.
    for (size_t playerId = 0; playerId < 2; playerId++)
    {
        printPlayerTurn (playerNames[playerId]);
        updateInterface (boards, marks, numberOfShips, nameOfShips, playerNames, playerId);
        placementOfShips(boards, marks, playerNames, numberOfShips, nameOfShips, locationOfShips, playerId);
    }

    uint idPlayer1 = 0;
    uint idPlayer2 = 1;

    printPlayerTurn(playerNames[idPlayer1]);
    updateInterface(boards, marks, numberOfShips, nameOfShips, playerNames, idPlayer1);

    // The core gameplay loop.
    while (!hasWinner(numberOfShips))
    {
        string msg;
        uint   shot[2];
        char   shotResult = takeShot(boards, marks, idPlayer2, shot);

        if (shotResult == 1)  // Hit
        {
            uint shipId = getShipId(locationOfShips, shot[0], shot[1], idPlayer2);

            if (isShipSunk(boards, locationOfShips, shipId, idPlayer2))
            {
                uint type = getTypeShip(locationOfShips[idPlayer2][shipId]) - 1;  // Find out what kind of ship sank (one-deck, double-deck, etc.).
                numberOfShips[idPlayer2][type]--;                                 // Reducing the number of ships by one.
                placeMarksOnBoardAroundShip(boards, locationOfShips, marks[2], shipId, idPlayer2);
                msg = "You have sunk the " + colorize(nameOfShips[type], "3;95", "36") + "! Your turn again.";
            }
            else
                msg = "You hit the ship! You may shoot again.";
        }
        else if (shotResult == 0)  // Miss
            msg = "You missed!";
        else
            msg = "You've already shot at that square!";

        updateInterface(boards, marks, numberOfShips, nameOfShips, playerNames, idPlayer1);
        cout << colorize("\n" + msg + "\n", "3;36");

        if (shotResult == 0)
        {
            swap(idPlayer1, idPlayer2);  // Set the next player's turn.
            printPlayerTurn(playerNames[idPlayer1]);
            updateInterface(boards, marks, numberOfShips, nameOfShips, playerNames, idPlayer1);
        }
    }

    updateInterface(boards, marks, numberOfShips, nameOfShips, playerNames, idPlayer1);
    printGameEnd(playerNames[getWinnerId(numberOfShips)]);
}

void initializeBoards(char boards[][10][10], const char mark)
{
    fill_n(boards[0][0], 2 * 10 * 10, mark);
};

void initializeShipCoordinates(uint locationOfShips[][10][2][2])
{
    fill_n(locationOfShips[0][0][0], 2 * 10 * 2 * 2, 10);
};

void placementOfShips(char boards[][10][10], const char marks[], const string playerNames[], uint numberOfShips[][4], const string nameOfShips[], uint locationOfShips[][10][2][2], const uint playerId)
{
    uint location[2][2]{};
    uint index = 0;

    for (size_t deck = 1, num = 4; deck <= 4; deck++, num--)  // Type of ships.
    {
        for (size_t j = 0; j < num; j++, index++)             // Number of ships.
        {
            cout << colorize("\nGive the coordinates x, y to place the ", "3;36")
                 << colorize(nameOfShips[deck - 1], "4;95")
                 << colorize(" (" + to_string(deck) + "-deck)!\n\n", "3;36")
                 << colorize("Left to place: " + to_string(num - j) + "\n", "3;36");

            getShipLocationFromUser(boards, marks[0], deck, playerId, location);

            numberOfShips[playerId][deck - 1]++;
            copy(location[0], location[1] + 2, locationOfShips[playerId][index][0]);
            placeShipOnBoard(boards, location, marks[0], playerId);

            updateInterface(boards, marks, numberOfShips, nameOfShips, playerNames, playerId);
        }
    }
};

int takeShot(char board[][10][10], const char marks[], const uint playerId, uint shot[])
{
    cout << colorize("\nEnter shot coordinates (x y):\n\n", "3;36");
    getPositiveNumericArrayOfUserInput("Target: ", shot, 2, 0, 9);

    char shotResult = board[playerId][shot[0]][shot[1]];

    if (shotResult == marks[0])  // Hit.
    {
        board[playerId][shot[0]][shot[1]] = marks[1];  // Set the hit mark.
        return 1;
    }

    if (shotResult == marks[3])  // Miss.
    {
        board[playerId][shot[0]][shot[1]] = marks[2];  // Set the miss mark.
        return 0;
    }

    return -1;  // This square has already been shot.
};

uint getWinnerId(const uint numberOfShips[][4])
{
    return (getNumberOfShips(numberOfShips, 0) == 0) ? 1 : 0;
};

void placeShipOnBoard(char board[][10][10], const uint location[][2], const char mark, const uint playerId)
{
    for (size_t i = location[0][0]; i <= location[1][0]; i++)
        for (size_t j = location[0][1]; j <= location[1][1]; j++)
            board[playerId][i][j] = mark;  // Set the ship's mark.
};

void placeMarksOnBoardAroundShip(char board[][10][10], const uint locationOfShips[][10][2][2], const char mark, const uint shipId, const uint playerId)
{
    uint area[2][2];  // Coordinates of the area around the ship.
    getAreaAroundShip(locationOfShips[playerId][shipId], area);

    for (size_t i = area[0][0]; i <= area[1][0]; i++)
        for (size_t j = area[0][1]; j <= area[1][1]; j++)
            if (i < locationOfShips[playerId][shipId][0][0] || i > locationOfShips[playerId][shipId][1][0] ||
                j < locationOfShips[playerId][shipId][0][1] || j > locationOfShips[playerId][shipId][1][1])
                board[playerId][i][j] = mark;  // Set the sea mark.
};

uint getShipId(const uint locationOfShips[][10][2][2], const uint x, const uint y, const uint playerId)
{
    uint id;  // Index of the locationOfShips in which the coordinates (x, y) match one of the ships.
    for (id = 0; id < 10; id++)
        if ((x <= locationOfShips[playerId][id][1][0]) && (x >= locationOfShips[playerId][id][0][0]) &&
            (y <= locationOfShips[playerId][id][1][1]) && (y >= locationOfShips[playerId][id][0][1]))
            break;

    return id;
};

uint getTypeShip(const uint location[][2])
{
    return location[1][0] - location[0][0] + location[1][1] - location[0][1] + 1;  // x2 - x1 + y2 - y1 + 1
};

uint getNumberOfShips(const uint numberOfShips[][4], const uint playerId)
{
    return numberOfShips[playerId][0] + numberOfShips[playerId][1] + numberOfShips[playerId][2] + numberOfShips[playerId][3]; // deck1 + deck2 + deck3 + deck4
};

void getAreaAroundShip(const uint ship[][2], uint area[][2])
{
    for (size_t i = 0; i < 2; i++)
    {
        area[0][i] = (ship[0][i] != 0) ? ship[0][i] - 1 : ship[0][i];
        area[1][i] = (ship[1][i] != 9) ? ship[1][i] + 1 : ship[1][i];
    }
};

void getPlayerNamesFromUser(string playerNames[])
{
    for (size_t i = 0; i < 2; i++)
    {
        playerNames[i] = getStringUserInput("Enter name of the Player " + to_string(i + 1) + ": ");
        if (playerNames[0] == playerNames[1])
        {
            cout << colorize("Error: Same names, choose a different name.", "3;31")  << clearLine(1);
            i = 0;
        }
    }
    cout << clearLine();
};

void getShipLocationFromUser(const char board[][10][10], const char mark, const uint type, const uint playerId, uint location[][2])
{
    string error;
    bool isError = false;
    while (true)
    {
        getPositiveNumericArrayOfUserInput("Start position: ", location[0], 2);
        getPositiveNumericArrayOfUserInput("End position:   ", location[1], 2);

        // Sort the coordinates so that the ship's coordinates start at the top left corner and end at the bottom right corner.
        if (location[0][0] > location[1][0]) swap(location[0][0], location[1][0]);
        if (location[0][1] > location[1][1]) swap(location[0][1], location[1][1]);

        if      (!isCoordinatesValid(location))                     error = "Error: Coordinates must be in the range from 0 to 9.";
        else if (isShipLocatedDiagonally(location))                 error = "Error: Ships must only be placed vertically or horizontally.";
        else if (getTypeShip(location) != type)                     error = "Error: This is not the " + to_string(type) + " deck ship.";
        else if (isShipsIntersect(board, mark, location, playerId)) error = "Error: This place is already taken.";
        else if (isShipsTouch(board, mark, location, playerId))     error = "Error: The ships must not touch.";
        else break;

        cout << clearLines((isError) ? 3 : 2) << colorize(error, "3;31") << '\n';
        isError = true;
    }
};

bool isCoordinatesValid(const uint location[][2])
{
    for (size_t i = 0; i < 4; i++)
        if ((location[0] + i)[0] > 9)
            return false;

    return true;
};

bool isShipLocatedDiagonally(const uint location[][2])
{
    return (location[0][0] != location[1][0]) && (location[0][1] != location[1][1]);  // (x1 != x2) && (y1 != y2)
};

bool isShipsIntersect(const char board[][10][10], const char mark, const uint location[][2], const uint playerId)
{
    for (size_t i = location[0][0]; i <= location[1][0]; i++)
        for (size_t j = location[0][1]; j <= location[1][1]; j++)
            if (board[playerId][i][j] == mark)  // Equal to the ship's mark.
                return true;

    return false;
};

bool isShipsTouch(const char board[][10][10], const char mark, const uint location[][2], const uint playerId)
{
    uint area[2][2];  // Coordinates of the area around the ship.
    getAreaAroundShip(location, area);
    return isShipsIntersect(board, mark, area, playerId);
};

bool isShipSunk(const char board[][10][10], const uint locationOfShips[][10][2][2], const uint shipId, const uint playerId)
{
    uint x1 = locationOfShips[playerId][shipId][0][0];
    uint y1 = locationOfShips[playerId][shipId][0][1];
    uint x2 = locationOfShips[playerId][shipId][1][0];
    uint y2 = locationOfShips[playerId][shipId][1][1];

    for (size_t i = x1; i <= x2; i++)
        for (size_t j = y1; j <= y2; j++)
            if (board[playerId][i][j] != board[playerId][x2][y2])
                return false;

    return true;
};

bool hasWinner(const uint numberOfShips[][4])
{
    return (getNumberOfShips(numberOfShips, 0) == 0) || (getNumberOfShips(numberOfShips, 1) == 0);
};

void printSplashScreen()
{
    cout << colorize(
        "\t\t   ___  ___ ______________   __________ _________   \n"
        "\t\t  / _ )/ _ /_  __/_  __/ /  / __/ __/ // /  _/ _ \\ \n"
        "\t\t / _  / __ |/ /   / / / /__/ _/_\\ \\/ _  // // ___/\n"
        "\t\t/____/_/ |_/_/   /_/ /____/___/___/_//_/___/_/    \n\n",
        "36");

    cout << setw(57) << colorize("Start game!\n", "5;36");
    cin.ignore(1000, '\n');
    clearInterface();
};

void printPlayerTurn(const string player)
{
    cout << colorize("\nPress enter to end your turn ...", "90");
    cin.ignore(1000, '\n');
    clearInterface();

    cout << colorize("Player " + player + "'s turn.\n", "3;36");
    cout << colorize("\nPress enter to continue ...", "90");
    cin.ignore(1000, '\n');
    clearInterface();
};

void printBoards(const char boards[][10][10], const char marks[], const uint playerId)
{
    string ship = colorize(string{marks[0]},   "37",    "90");
    string hit  = colorize(string{marks[1]},   "31",    "90");
    string miss = colorize(string{marks[2]},   "94",    "90");
    string sea  = colorize(string{marks[3]}, "2;90", "22;90");

    cout << "\033[90m"
            "\t     0 1 2 3 4 5 6 7 8 9   \t\t     0 1 2 3 4 5 6 7 8 9 \n"
            "\t    ---------------------  \t\t    ---------------------\n";

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t p = 0; p < 2; p++)
        {
            cout << "\t " << i << " | ";
            for (size_t j = 0; j < 10; j++)
            {
                if      (boards[(p + playerId) % 2][i][j] == marks[0]) cout << ((p == 0) ? ship : sea);  // Hiding the ships on the second game board.
                else if (boards[(p + playerId) % 2][i][j] == marks[1]) cout << hit;
                else if (boards[(p + playerId) % 2][i][j] == marks[2]) cout << miss;
                else                                                   cout << sea;
                cout << ' ';
            }
            cout << "|\t";
        }
        cout << '\n';
    }

    cout << "\t    ---------------------  \t\t    ---------------------  \033[m\n";
};

void printStatistics(const string nameOfShips[], const uint numberOfShips[][4], const string playerNames[], const uint playerId)
{
    cout << left << "\t    " << setw(40) << playerNames[playerId] << colorize(playerNames[(playerId + 1) % 2], "90") << right << "\n"
         << "\t    ----------------" << setw(49) << "\033[90m ----------------\033[m\n"
         << left
         << "\t    " << setw(14) << nameOfShips[3] << numberOfShips[playerId][3] << setw(30) << "\033[90m" << setw(14) << nameOfShips[3] << numberOfShips[(playerId + 1) % 2][3] << "\033[m\n"
         << "\t    " << setw(14) << nameOfShips[2] << numberOfShips[playerId][2] << setw(30) << "\033[90m" << setw(14) << nameOfShips[2] << numberOfShips[(playerId + 1) % 2][2] << "\033[m\n"
         << "\t    " << setw(14) << nameOfShips[1] << numberOfShips[playerId][1] << setw(30) << "\033[90m" << setw(14) << nameOfShips[1] << numberOfShips[(playerId + 1) % 2][1] << "\033[m\n"
         << "\t    " << setw(14) << nameOfShips[0] << numberOfShips[playerId][0] << setw(30) << "\033[90m" << setw(14) << nameOfShips[0] << numberOfShips[(playerId + 1) % 2][0] << "\033[m\n\n"
         << right;
};

void printGameEnd(const string winner)
{
    cout << colorize("\n\t\t\t\t      GAME OVER", "5;36")
         << colorize("\n\t\t\t\t  Player " + winner + " wins!\n", "3;95")
         << colorize("\t\t\t    You destroyed the enemy fleet!\n\n", "3;36")
         << colorize("\t\t\t   Press enter to exit the game ...", "90");
};

void updateInterface(const char boards[][10][10], const char marks[], const uint numberOfShips[][4], const string nameOfShips[], const string playerNames[], const uint playerId)
{
    clearInterface();
    printBoards(boards, marks, playerId);
    printStatistics(nameOfShips, numberOfShips, playerNames, playerId);
};

void clearInterface()
{
    clearConsole();
    cout << "Task 14.8 Battleship.* (additional task)\n"
            "-------------------------------------------\n\n";
}
