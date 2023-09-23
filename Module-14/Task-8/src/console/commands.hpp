#pragma once

#include <string>

/**
 * @brief Clear console screen.
 */
void clearConsole();

/**
 * @brief Clears a entire line at a given line number.
 * @param number Line number starting from the bottom.
 * @return The escape sequence codes.
 */
std::string clearLine(const unsigned number = 0);

/**
 * @brief Clear all lines from a given line number to the end of the screen.
 * @param number Line number starting from the bottom.
 * @return The escape sequence codes.
 */
std::string clearLines(const unsigned number);

/**
 * @brief Set the color of the text output to the console.
 * @param text      Output text to the console.
 * @param colorCode Color code in escape sequence.
 * @param resetCode Color code Escape sequence at the end of the text. By default the color is reset to the original.
 * @return Text with specified escape sequence color codes.
 */
std::string colorize(const std::string text, const std::string colorCode, const std::string resetCode = "0");
