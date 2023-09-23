#include "bubble_wrap.hpp"

#include <iostream>
#include "../console/user_input.hpp"

using namespace std;

void startPoppingBubbleWrap()
{
    bool bubbleWrap[12][12];
    unsigned wholeBubbles = 12 * 12;  // The number of whole bubbles.

    // The coordinates of the region where the bubbles will pop.
    unsigned startOfRegion[2];
    unsigned endOfRegion[2];

    initializeBubbleWrap(bubbleWrap);
    drawBubbleWrap(bubbleWrap);

    while (wholeBubbles != 0)
    {
        getRegionCoordinatesFromUser(startOfRegion, endOfRegion);
        wholeBubbles -= popBubbles(bubbleWrap, startOfRegion, endOfRegion);
        drawBubbleWrap(bubbleWrap);
    }
}

void initializeBubbleWrap(bool bubbleWrap[][12])
{
    fill_n(bubbleWrap[0], (12 * 12), true);
}

void drawBubbleWrap(const bool bubbleWrap[][12])
{
    for (size_t i = 0; i < 12; i++)
    {
        cout << "\n\t";
        for (size_t j = 0; j < 12; j++)
            cout << ((bubbleWrap[i][j]) ? 'O' : 'x') << ' ';
    }
    cout << '\n';
}

void getRegionCoordinatesFromUser(unsigned start[2], unsigned end[2])
{
    cout << "\nEnter the coordinates of the region where you want to pop the bubbles, from 1 to 12: \n\n";
    getPositiveNumericArrayOfUserInput("Start of region (x y): ", start, 2, 1, 12);
    getPositiveNumericArrayOfUserInput("End of region   (x y): ", end,   2, 1, 12);

    // Converting the range of values from 1 to 12 to the range from 0 to 11.
    for (size_t i = 0; i < 2; i++)
    {
        start[i]--;
        end[i]--;
    }
}

unsigned popBubbles(bool bubbleWrap[][12], unsigned start[2], unsigned end[2])
{
    unsigned poppedBubbles = 0;  // The number of bubbles burst.

    // The starting coordinates of the region are the top left corner, and the end coordinates are the bottom right.
    if (start[0] >= end[0]) swap(start[0], end[0]);
    if (start[1] >= end[1]) swap(start[1], end[1]);

    cout << '\n';
    for (size_t i = start[0]; i <= end[0]; i++)
    {
        for (size_t j = start[1]; j <= end[1]; j++)
        {
            if (bubbleWrap[i][j])
            {
                bubbleWrap[i][j] = false;
                poppedBubbles++;
                cout << "Pop! ";
            }
        }
    }
    cout << '\n';
    return poppedBubbles;
}
