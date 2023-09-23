#pragma once

#include <string>

/**
 * @brief Comparison of two matrices.
 * @param matrixA The first matrix.
 * @param matrixB The second matrix.
 * @return True if the matrices are equal, false otherwise.
 */
bool compareMatrices(const int matrixA[][4], const int matrixB[][4]);

/**
 * @brief Convert the given matrix to a diagonal matrix.
 * @param matrix The matrix.
 */
void convertMatrixToDiagonal(int matrix[][4]);

/**
 * @brief Get the user entered matrix from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param matrix The user matrix.
 * @param msg    This message will be printed to the console before user input.
 */
void getInputMatrixFromUser(int matrix[][4], const std::string msg);

/**
 * @brief Print the matrix to the console.
 * @param matrix The matrix.
 */
void printMatrix(const int matrix[][4]);
