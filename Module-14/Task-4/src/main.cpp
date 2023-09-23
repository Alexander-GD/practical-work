#include <iostream>
#include <vector>

#include "console/user_input.hpp"
#include "matrix/matrix.hpp"

using namespace std;

int main()
{
    cout << "Task 14.4 Multiplication of a matrix by a vector.\n"
         << "----------------------------------------------------\n\n";

    float matrix[4][4];
    vector<float> vec(4);

    getInputMatrixFromUser(matrix, "Enter a 4x4 matrix of numbers: \n");
    vec = getFloatNumberSequenceOfUserInput("\nEnter a sequence of 4 numbers: \n", 4);

    vector<float> result = matrixMultiplication(matrix, vec);

    cout << "\nThe result of multiplication: \n";
    for (size_t i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
    cout << endl;

    preventConsoleClosing();
    return 0;
}
