#include <array>
#include <string>
#include <vector>

/**
 * @brief Run the ATM simulation.
 */
void startAtmSimulation();

/**
 * @brief Load the ATM state from binary file into array.
 * @param filePath Path to ATM state file.
 * @param atm      Array for storing ATM state.
 */
void loadAtmState(const std::string& filePath, std::vector<unsigned>& atm);

/**
 * @brief Save the ATM state from an array to a binary file.
 * @param filePath Path to ATM state file.
 * @param atm      An array that stores the state of the ATM.
 */
void saveAtmState(const std::string& filePath, const std::vector<unsigned>& atm);

/**
 * @brief Refill the ATM with banknotes to the maximum.
 * @param atm                  An array that stores the state of the ATM.
 * @param maxNumberOfBanknotes Maximum number of banknotes.
 */
void replenishAtm(std::vector<unsigned>& atm, const unsigned maxNumberOfBanknotes);

/**
 * @brief Withdrawal of money from an ATM.
 * @param atm       An array that stores the state of the ATM.
 * @param banknotes An array containing all types of banknotes.
 */
void withdrawMoneyFromAtm(std::vector<unsigned>& atm, const std::array<unsigned, 6>& banknotes);

/**
 * @brief Print the current state of the ATM to the console.
 * @param atm       An array that stores the state of the ATM.
 * @param banknotes An array containing all types of banknotes.
 */
void printAtmState(const std::vector<unsigned>& atm, const std::array<unsigned, 6>& banknotes);

/**
 * @brief Is the ATM empty.
 * @param atm An array that stores the state of the ATM.
 * @return True if the ATM is empty, otherwise false.
 */
bool isAtmEmpty(const std::vector<unsigned>& atm);

/**
 * @brief Total number of banknotes contained in the ATM.
 * @param atm An array that stores the state of the ATM.
 * @return The number of banknotes in the ATM.
 */
unsigned numberOfBanknotesInAtm(const std::vector<unsigned>& atm);

/**
 * @brief Total amount of money contained in the ATM.
 * @param atm       An array that stores the state of the ATM.
 * @param banknotes An array containing all types of banknotes.
 * @return The total amount of money in the ATM.
 */
unsigned amountOfMoneyInAtm(const std::vector<unsigned>& atm, const std::array<unsigned, 6>& banknotes);

/**
 * @brief Get ATM operation commands from the user.
 * @return The ATM command (withdrawal, replenish, exit).
 */
char getCommandFromUser();

/**
 * @brief Get the amount of money from the user to withdraw from an ATM.
 * @return The amount of money to be withdrawn from an ATM.
 */
unsigned getWithdrawalAmountFromUser();
