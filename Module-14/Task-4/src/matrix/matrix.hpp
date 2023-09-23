#pragma once

#include <string>
#include <vector>

/**
 * @brief Multiplication of a vector by a matrix.
 * @param matrix The matrix.
 * @param vec    The vector.
 * @return The result of multiplying a vector by a matrix.
 */
std::vector<float> matrixMultiplication(const float matrix[][4], const std::vector<float> vec);

/**
 * @brief Get the user entered matrix from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param matrix The user matrix.
 * @param msg    This message will be printed to the console before user input.
 */
void getInputMatrixFromUser(float matrix[][4], const std::string msg);
