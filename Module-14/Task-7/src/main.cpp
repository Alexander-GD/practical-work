#include <iostream>

#include "console/user_input.hpp"
#include "game/minecraft.hpp"

using namespace std;

void printArray(const bool arr[][5]);

int main()
{
    cout << "Task 14.7 Almost \"Minecraft\".* (additional task)\n"
         << "---------------------------------------------------\n\n";

    bool world[5][5][10];
    int  heightMap[5][5];
    bool slice[5][5];

    getHeightMapFromUser(heightMap, "Enter the 5 x 5 matrix of heights with a value from 1 to 10:\n");
    createWorld(world, heightMap);

    while (int level = getNumericUserInput("Enter the horizontal slice level from 1 to 10 (0 for exit): ", 0, 10))
    {
        horizontalSliceOfWorld(world, slice, level - 1);
        printArray(slice);
    }

    preventConsoleClosing();
    return 0;
}

void printArray(const bool arr[][5])
{
    for (size_t i = 0; i < 5; i++)
    {
        cout << "\n\t";
        for (size_t j = 0; j < 5; j++)
            cout << arr[i][j] << ' ';
    }
    cout << "\n\n";
}
