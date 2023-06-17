#include <iostream>
#include <limits>

#include "email_address.hpp"

using namespace std;

int main()
{
    cout << "Task 11.2 | Checking the validity of an email address.\n";
    cout << "---------------------------------------------------------\n\n";

    string address;

    cout << "Enter email address: ";
    getline(cin, address);
    cout << "\n";

    if (isValidEmailAddress(address))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    // Prevent console closing.
    cin.clear();
    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    cin.get();
    return 0;
}
