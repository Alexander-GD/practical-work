#include <iostream>
#include "console/user_input.hpp"

using namespace std;

bool compareFloatGreaterEquals(const float a, const float b, const float epsilon)
{
    return a - b >= epsilon;
}

int main()
{
    cout << "Task 16.1 Speedometer\n"
         << "------------------------\n\n";

    float maxSpeed      = 150.0f;
    float currentSpeed  = 0.0f;
    char  speedometer[] = "150.0 km/h";
    float deltaSpeed;

    do
    {
        deltaSpeed    = getFloatingPointNumericUserInput("\nEnter speed delta: ");
        currentSpeed += deltaSpeed;

        if (compareFloatGreaterEquals(currentSpeed, maxSpeed, 0.01f))
            currentSpeed = maxSpeed;

        if (compareFloatGreaterEquals(0.0f, currentSpeed, 0.01f))
            currentSpeed = 0.0f;

        snprintf(speedometer, size(speedometer), "%.1f km/h", currentSpeed);
        cout << "\nSpeed: " << speedometer << "\n";

    } while (compareFloatGreaterEquals(currentSpeed, 0.0f, 0.01f));

    preventConsoleClosing();
    return 0;
}
