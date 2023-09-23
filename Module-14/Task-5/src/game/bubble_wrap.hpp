#pragma once

#include <string>

/**
 * @brief Starts the process of popping bubble wrap.
 */
void startPoppingBubbleWrap();

/**
 * @brief Fills the bubble wrap array with true values.
 * @param bubbleWrap The bubble wrap.
 */
void initializeBubbleWrap(bool bubbleWrap[][12]);

/**
 * @brief Display the bubble wrap in the console.
 * @param bubbleWrap The bubble wrap.
 */
void drawBubbleWrap(const bool bubbleWrap[][12]);

/**
 * @brief Get from the user the coordinates of the region where the bubbles need to pop.
 * @param start The starting coordinates of the region.
 * @param end   The end coordinates of the region.
 */
void getRegionCoordinatesFromUser(unsigned start[2], unsigned end[2]);

/**
 * @brief Pops bubbles in the specified region on the bubble wrap.
 * @param bubbleWrap The bubble wrap
 * @param start      The starting coordinates of the region.
 * @param end        The end coordinates of the region.
 * @return           The number of popped bubbles.
 */
unsigned popBubbles(bool bubbleWrap[][12], unsigned start[2], unsigned end[2]);
