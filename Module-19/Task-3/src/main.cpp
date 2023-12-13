#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

// Returns the total amount paid out and the client with the maximum payout amount.
size_t totalAmountOfPayments(ifstream& statement, string& customer, size_t& maxPayout);

int main()
{
    cout << "Task 19.3 Implementation of the statement reading program\n"
         << "------------------------------------------------------------\n\n";

    string filePath{"data/statement.txt"};
    string customer;
    size_t maxPayout     = 0;
    size_t totalPayments = 0;

    ifstream statement(filePath);

    if (statement.is_open()) {
        totalPayments = totalAmountOfPayments(statement, customer, maxPayout);

        cout << "Total amount of payments: " << totalPayments << '\n'
             << "The maximum payout:       " << customer << ", " << maxPayout << endl;
    } else {
        cerr << "Error: Failed to open file " << quoted(filePath) << endl;
    }

    cin.get();
    return 0;
}

size_t totalAmountOfPayments(ifstream& statement, string& customer, size_t& maxPayout)
{
    string name;
    string surname;
    size_t payout;
    size_t totalPayments = 0;

    string buffer;
    stringstream ss;

    while (getline(statement, buffer)) {
        ss.str(buffer);
        ss >> name >> surname >> payout;

        totalPayments += payout;
        if (payout > maxPayout) {
            maxPayout = payout;
            customer  = string{name + " " + surname};
        }
        ss.seekg(0);
    }
    return totalPayments;
}
