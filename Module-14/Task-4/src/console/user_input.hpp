#pragma once

#include <string>
#include <vector>
#include <cfloat>

/**
 * @brief Get numeric user input from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param msg  This message will be printed to the console before user input.
 * @param low  The lower limit of the range of valid values for input.
 * @param high The upper limit of the range of valid values for input.
 * @return The number entered by the user.
 */
int getNumericUserInput(const std::string msg, const int low = INT_MIN, const int high = INT_MAX);

/**
 * @brief Get positive numeric user input from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param msg  This message will be printed to the console before user input.
 * @param low  The lower limit of the range of valid values for input.
 * @param high The upper limit of the range of valid values for input.
 * @return The positive number entered by the user.
 */
unsigned getPositiveNumericUserInput(const std::string msg, const unsigned low = 0, const unsigned high = UINT_MAX);

/**
 * @brief Get the user's floating point input from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param msg  This message will be printed to the console before user input.
 * @param low  The lower limit of the range of valid values for input.
 * @param high The upper limit of the range of valid values for input.
 * @return The floating point number entered by the user.
 */
float getFloatingPointNumericUserInput(const std::string msg, const float low = -FLT_MAX, const float high = FLT_MAX);

/**
 * @brief Get the user's string input from the console.
 * @param msg This message will be printed to the console before user input.
 * @return The string entered by the user.
 */
std::string getStringUserInput(const std::string msg);

/**
 * @brief Get the numerical sequence of user input from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param msg  This message will be printed to the console before user input.
 * @param size The size of the sequence. Zero value - any size of the sequence.
 * @param low  The lower limit of the range of valid values for input.
 * @param high The upper limit of the range of valid values for input.
 * @return The user-defined sequence as a vector of integers.
 */
std::vector<int> getNumericSequenceOfUserInput(const std::string msg, const size_t size = 0, const int low = INT_MIN, const int high = INT_MAX);

/**
 * @brief Get the user's floating point input from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param msg  This message will be printed to the console before user input.
 * @param size The size of the sequence. Zero value - any size of the sequence.
 * @param low  The lower limit of the range of valid values for input.
 * @param high The upper limit of the range of valid values for input.
 * @return The user-defined sequence as a vector of floating-point numbers.
 */
std::vector<float> getFloatNumberSequenceOfUserInput(const std::string msg, const size_t size = 0, const float low = -FLT_MAX, const float high = FLT_MAX);

/**
 * @brief Get the numerical sequence of user input from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param msg  This message will be printed to the console before user input.
 * @param size Array size.
 * @param low  The lower limit of the range of valid values for input.
 * @param high The upper limit of the range of valid values for input.
 * @return The user-defined sequence as an array of integers.
 */
void getNumericArrayOfUserInput(const std::string msg, int arr[], const size_t size, const int low = INT_MIN, const int high = INT_MAX);

/**
 * @brief Get the user's floating point input from the console.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param msg  This message will be printed to the console before user input.
 * @param size Array size.
 * @param low  The lower limit of the range of valid values for input.
 * @param high The upper limit of the range of valid values for input.
 * @return The user-defined sequence as an array of floating-point numbers.
 */
void getFloatNumberArrayOfUserInput(const std::string msg, float arr[], const size_t size, const float low = -FLT_MAX, const float high = FLT_MAX);

/**
 * @brief Preventing the console window from closing.
 */
void preventConsoleClosing();
