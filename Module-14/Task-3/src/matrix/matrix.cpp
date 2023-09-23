#include "matrix.hpp"

#include <iostream>
#include "../console/user_input.hpp"

using namespace std;

bool compareMatrices(const int matrixA[][4], const int matrixB[][4])
{
    return equal(matrixA[0], (matrixA + 4)[0], matrixB[0]);
}

void convertMatrixToDiagonal(int matrix[][4])
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            if (i != j) matrix[i][j] = 0;
}

void getInputMatrixFromUser(int matrix[][4], const string msg)
{
    cout << msg;
    int row[4];
    for (size_t i = 0; i < 4; i++)
    {
        getNumericArrayOfUserInput("> ", row, 4);
        for (size_t j = 0; j < 4; j++)
            matrix[i][j] = row[j];
    }
}

void printMatrix(const int matrix[][4])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
            cout << matrix[i][j] << ' ';
        cout << '\n';
    }
}
