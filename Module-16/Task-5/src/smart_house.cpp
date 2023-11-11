#include "smart_house.hpp"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

enum Switches : unsigned
{
    LIGHTS_INSIDE       = 1,
    LIGHTS_OUTSIDE      = 2,
    HEATERS             = 4,
    WATER_PIPE_HEATING  = 8,
    CONDITIONER         = 16
};

void smartHouseSimulation()
{
    int  temperatureInside[1];
    int  temperatureOutside[1];
    bool isMovement[1];
    bool isLightOn[1];

    unsigned switchesState = 0;
    unsigned currentSwitchesState[1]{0};

    for (size_t i = 0; i < 48; i++)
    {
        unsigned time = i % 24;
        
        cout << "[" << setw(2) << setfill('0') << time << ":00] "
             << "Temperature inside, temperature outside, movement, lights:\n";

        getSensorDataFromUser(temperatureInside, temperatureOutside, isMovement, isLightOn);
        smartPanel(currentSwitchesState, time, temperatureInside[0], temperatureOutside[0], isMovement[0], isLightOn[0]);
        printStateOfHouse(time, currentSwitchesState[0], switchesState);

        switchesState = currentSwitchesState[0];
    }
}

void smartPanel(unsigned switches[], const unsigned time, const int temperatureInside, const int temperatureOutside, const bool movement, const bool lights)
{
    if (temperatureOutside < 0)
        switches[0] |= WATER_PIPE_HEATING; // on
    if (temperatureOutside > 5)
        switches[0] &= ~WATER_PIPE_HEATING; // off

    if ((time >= 16 || time < 5) && movement)
        switches[0] |= LIGHTS_OUTSIDE; // on
    else
        switches[0] &= ~LIGHTS_OUTSIDE; // off

    if (temperatureInside < 22)
        switches[0] |= HEATERS; // on
    if (temperatureInside >= 25)
        switches[0] &= ~HEATERS; // off

    if (temperatureInside >= 30)
        switches[0] |= CONDITIONER; // on
    if (temperatureInside <= 25)
        switches[0] &= ~CONDITIONER; // off

    if (lights)
        switches[0] |= LIGHTS_INSIDE; // on
    else
        switches[0] &= ~LIGHTS_INSIDE; // off
}

void printStateOfHouse(const unsigned time, const unsigned switchesState, const unsigned previousSwitchesState)
{
    unsigned changedState = switchesState ^ previousSwitchesState;

    if (changedState & LIGHTS_INSIDE)      cout << "\tLights "             << ((switchesState & LIGHTS_INSIDE)      ? "ON" : "OFF") << "!\n";
    if (changedState & LIGHTS_OUTSIDE)     cout << "\tLights outside "     << ((switchesState & LIGHTS_OUTSIDE)     ? "ON" : "OFF") << "!\n";
    if (changedState & HEATERS)            cout << "\tHeaters "            << ((switchesState & HEATERS)            ? "ON" : "OFF") << "!\n";
    if (changedState & WATER_PIPE_HEATING) cout << "\tWater pipe heating " << ((switchesState & WATER_PIPE_HEATING) ? "ON" : "OFF") << "!\n";
    if (changedState & CONDITIONER)        cout << "\tConditioner "        << ((switchesState & CONDITIONER)        ? "ON" : "OFF") << "!\n";

    if (switchesState & LIGHTS_INSIDE)
    {
        int colorTemperature = 5000;
        if (time >= 16 && time <= 20) colorTemperature -= (5000 - 2700) / (20 - 16) * static_cast<int>(time - 16);
        else if (time < 16)           colorTemperature  = 5000;
        else                          colorTemperature  = 2700;

        cout << "\tColor temperature: " << colorTemperature << "K\n";
    }
    cout << "\n";
}

void getSensorDataFromUser(int temperatureInside[], int temperatureOutside[], bool movement[], bool lights[])
{
    string isMovement;
    string isLightOn;
    string input;

    while (true)
    {
        cout << "\t";
        getline(cin, input);
        std::stringstream ss(input);

        if ((ss >> temperatureInside[0] >> temperatureOutside[0] >> isMovement >> isLightOn).fail() || !ss.eof() ||
            (temperatureInside[0]  < -60 || temperatureInside[0]  > 60) || 
            (temperatureOutside[0] < -60 || temperatureOutside[0] > 60) ||
            (isMovement != "yes" && isMovement !=  "no") || 
            (isLightOn  != "on"  && isLightOn  != "off"))
        {
            cerr << "\tError: Invalid input\n\n";
        }
        else
        {
            movement[0] = (isMovement == "yes");
            lights[0]   = (isLightOn  == "on");
            break;
        }
    }
}
