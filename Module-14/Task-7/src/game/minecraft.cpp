#include "minecraft.hpp"

#include <iostream>
#include "../console/user_input.hpp"

using namespace std;

void createWorld(bool world[][5][10], const int heightMap[][5])
{
    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            for (int k = 0; k < 10; k++)
                world[i][j][k] = (k < heightMap[i][j]) ? true : false;
}

void horizontalSliceOfWorld(const bool world[][5][10], bool slice[][5], const int level)
{
    if (level < 0 || level > 9)
        return;

    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            slice[i][j] = world[i][j][level];
}

void getHeightMapFromUser(int heightMap[][5], const string msg)
{
    cout << msg;
    for (size_t i = 0; i < 5; i++)
        getNumericArrayOfUserInput("> ", heightMap[i], 5, 1, 10);
    cout << endl;
}
