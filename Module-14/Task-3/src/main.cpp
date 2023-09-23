#include <iostream>

#include "console/user_input.hpp"
#include "matrix/matrix.hpp"

using namespace std;

int main()
{
    cout << "Task 14.3 Matrix.\n"
         << "--------------------\n\n";

    int matrixA[4][4];
    int matrixB[4][4];

    getInputMatrixFromUser(matrixA, "Enter the first integer 4x4 matrix: \n");
    getInputMatrixFromUser(matrixB, "\nEnter the second integer 4x4 matrix: \n");

    if (compareMatrices(matrixA, matrixB))
    {
        convertMatrixToDiagonal(matrixA);

        cout << "\nThe matrices are equal!\n\n";
        cout << "Matrix in diagonal form:\n\n";
        printMatrix(matrixA);
    }
    else
        cout << "\nThe matrices are not equal!\n";

    preventConsoleClosing();
    return 0;
}
