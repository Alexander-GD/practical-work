#include "matrix.hpp"

#include <iostream>
#include "../console/user_input.hpp"

using namespace std;

vector<float> matrixMultiplication(const float matrix[][4], const vector<float> vec)
{
    vector<float> result(4);
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            result[i] += matrix[i][j] * vec[j];

    return result;
}

void getInputMatrixFromUser(float matrix[][4], const string msg)
{
    cout << msg;
    float row[4];
    for (size_t i = 0; i < 4; i++)
    {
        getFloatNumberArrayOfUserInput("> ", row, 4);
        for (size_t j = 0; j < 4; j++)
            matrix[i][j] = row[j];
    }
}
