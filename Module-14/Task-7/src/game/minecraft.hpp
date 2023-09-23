#pragma once

#include <string>

/**
 * @brief Initializes the world matrix with boolean values based on the height map.
 * @param world     The 3D matrix of the world.
 * @param heightMap The height map.
 */
void createWorld(bool world[][5][10], const int heightMap[][5]);

/**
 * @brief Gets a 2d array of a horizontal slice of the world by the specified height level.
 * @param world The 3D matrix of the world.
 * @param slice Horizontal slice of the world.
 * @param level Horizontal slice height level.
 */
void horizontalSliceOfWorld(const bool world[][5][10], bool slice[][5], const int level);

/**
 * @brief Get the height map from the user.
 *        Until the user enters valid input, the error message "Error: Invalid Input." will be displayed.
 * @param heightMap The array of height map.
 * @param msg       This message will be printed to the console before user input.
 */
void getHeightMapFromUser(int heightMap[][5], const std::string msg);
