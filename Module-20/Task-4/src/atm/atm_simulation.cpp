#include "atm_simulation.hpp"

#include <format>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

enum Command : char { REPLENISH = '+', WITHDRAW = '-', EXIT = 'e' };

void startAtmSimulation()
{
    vector<unsigned>         atm;
    const string             filePathAtmState("atm_state.bin");
    const unsigned           maxNumberOfBanknotes  = 1000;
    const array<unsigned, 6> banknotes{5000, 2000, 1000, 500, 200, 100};

    loadAtmState(filePathAtmState, atm);

    while (true) {
        printAtmState(atm, banknotes);
        Command command = static_cast<Command>(getCommandFromUser());

        if (command == REPLENISH) {
            cout << "\n> Processing a replenishment operation...\n\n\n";
            atm.resize(banknotes.size());
            replenishAtm(atm, maxNumberOfBanknotes);
        }
        else if (command == WITHDRAW) {
            cout << "\n> Processing a withdrawal operation...\n";
            withdrawMoneyFromAtm(atm, banknotes);
        }
        else if (command == EXIT) {
            cout << "\n> Exit from ATM!\n";
            break;
        }
        cin.get();
    }

    saveAtmState(filePathAtmState, atm);
}

void loadAtmState(const string& filePath, vector<unsigned>& atm)
{
    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        cout << "\n> ATM empty!\n\n\n";
        return;
    }

    for (unsigned banknote; file.read(reinterpret_cast<char*>(&banknote), sizeof(banknote));)
        atm.push_back(banknote);
}

void saveAtmState(const string& filePath, const vector<unsigned>& atm)
{
    if (atm.empty())
        return;

    ofstream file(filePath, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file \"" << filePath << "\"\n";
        return;
    }

    file.write(reinterpret_cast<const char*>(atm.data()), static_cast<streamsize>(atm.size() * sizeof(atm[0])));
}

void replenishAtm(vector<unsigned>& atm, const unsigned maxNumberOfBanknotes)
{
    unsigned totalBanknotes            = numberOfBanknotesInAtm(atm);
    unsigned requiredNumberOfBanknotes = maxNumberOfBanknotes - totalBanknotes;

    if (totalBanknotes == maxNumberOfBanknotes)
        return;

    srand(time(nullptr));

    for (size_t i = 0; i < atm.size(); i++) {
        unsigned r = static_cast<unsigned>(rand()) % requiredNumberOfBanknotes;
        atm[i] += r;
        requiredNumberOfBanknotes -= r;
    }
    atm.back() += requiredNumberOfBanknotes;
}

void withdrawMoneyFromAtm(vector<unsigned>& atm, const array<unsigned, 6>& banknotes)
{
    if (isAtmEmpty(atm)) {
        cout << "\n> ATM empty!\n\n\n";
        return;
    }

    unsigned amount     = getWithdrawalAmountFromUser();
    unsigned tempAmount = amount;

    for (size_t i = 0; i < atm.size(); i++) {
        unsigned countBanknote = tempAmount / banknotes[i];
        tempAmount -= (atm[i] > countBanknote) ? countBanknote * banknotes[i] : atm[i] * banknotes[i];
    }

    if (tempAmount != 0) {
        cout << "\n> FAILURE | The operation to withdraw this amount is impossible!\n\n\n";
        return;
    }

    for (size_t i = 0; i < atm.size(); i++) {
        unsigned countBanknote = amount / banknotes[i];
        amount -= (atm[i] > countBanknote) ? countBanknote * banknotes[i] : atm[i] * banknotes[i];
        atm[i] -= (atm[i] > countBanknote) ? countBanknote : atm[i];
    }

    cout << "\n> Cash withdrawal. Don't forget to pick up the money!\n\n\n";
}

void printAtmState(const vector<unsigned>& atm, const array<unsigned, 6>& banknotes)
{
    if (atm.empty())
        return;

    cout << "\n\n"
         << "\t+=============== ATM ===============+\n"
         << "\t|-----------------------------------|\n"
         << "\t| Banknote | Quantity |     Sum     |\n"
         << "\t|-----------------------------------|\n";

    for (size_t i = 0; i < atm.size(); i++)
        cout << format("\t|{:>8}  |{:>8}  |{:>11}  |\n", banknotes[i], atm[i], banknotes[i] * atm[i]);

    cout << "\t|-----------------------------------|\n"
         << format("\t| {:<9}|{:>8}  |{:>11}  |\n", "Total", numberOfBanknotesInAtm(atm), amountOfMoneyInAtm(atm, banknotes))
         << "\t+-----------------------------------+\n";
}

bool isAtmEmpty(const vector<unsigned>& atm)
{
    bool isAtmEmpty = true;
    for (const unsigned& banknote : atm)
        if (banknote != 0)
            isAtmEmpty = false;

    return (atm.empty() || isAtmEmpty);
}

unsigned numberOfBanknotesInAtm(const vector<unsigned>& atm)
{
    unsigned count = 0;
    for (const unsigned& banknote : atm)
        count += banknote;

    return count;
}

unsigned amountOfMoneyInAtm(const vector<unsigned>& atm, const array<unsigned, 6>& banknotes)
{
    unsigned sum = 0;
    for (size_t i = 0; i < atm.size(); i++)
        sum += atm[i] * banknotes[i];

    return sum;
}

char getCommandFromUser()
{
    string input;
    while (true) {
        cout << "\tCOMMANDS: Replenish: '+'\n"
             << "\t          Withdraw:  '-'\n"
             << "\t          Exit:      'e'\n\n";

        cout << "Enter a command to select the operation type: ";
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start != string::npos) {
            input = input.substr(start, last - start + 1);

            if (input.length() == 1 && (input.front() == WITHDRAW || input.front() == REPLENISH || input.front() == EXIT)) {
                return input.front();
            }
        }
        cerr << "Error: Invalid input\n\n";
    }
    return 0;
}

unsigned getWithdrawalAmountFromUser()
{
    string input;
    istringstream iss;

    while (true) {
        cout << "\nEnter the amount to withdraw: ";
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start != string::npos && input[start] != '-') {
            iss.str(input.substr(start, last - start + 1));

            if (unsigned amount; (iss >> amount) && iss.eof() && amount != 0 && (amount % 100) == 0)
                return amount;
        }
        cerr << "Error: Invalid input\n\n";
        iss.clear();
    }
}
