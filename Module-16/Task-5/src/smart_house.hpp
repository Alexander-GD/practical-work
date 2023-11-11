#pragma once

/**
 * @brief Runs a smart home simulation.
 */
void smartHouseSimulation();

/**
 * @brief Sets the state of switches depending on sensor readings.
 * @param switches           Switches.
 * @param time               Current time.
 * @param temperatureInside  Current inside temperature.
 * @param temperatureOutside Current outside temperature.
 * @param movement           Movement outside.
 * @param lights             Lights on.
 */
void smartPanel(unsigned switches[], const unsigned time, const int temperatureInside, const int temperatureOutside, const bool movement, const bool lights);

/**
 * @brief Print the state of the house to the console.
 * @param time                  Current time.
 * @param switchesState         Current state of switches.
 * @param previousSwitchesState Previous state of switches.
 */
void printStateOfHouse(const unsigned time, const unsigned switchesState, const unsigned previousSwitchesState);

/**
 * @brief Get temperature, movement and light data from the user.
 * @param temperatureInside  Current inside temperature.
 * @param temperatureOutside Current outside temperature.
 * @param movement           Movement outside.
 * @param lights             Lights on.
 */
void getSensorDataFromUser(int temperatureInside[], int temperatureOutside[], bool movement[], bool lights[]);
