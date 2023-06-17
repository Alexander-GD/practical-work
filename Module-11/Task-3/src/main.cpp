#include <iostream>
#include <limits>

#include "ip_address.hpp"

using namespace std;

int main()
{
    cout << "Task 11.3 | Validation of the IP address.\n";
    cout << "--------------------------------------------\n\n";

    string address;

    cout << "Enter IP address: ";
    getline(cin, address);
    cout << "\n";

    if (isIpAddressValid(address))
    {
        cout << "Valid\n";
    }
    else
    {
        cout << "Invalid\n";
    }

    // Prevent console closing.
    cin.clear();
    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    cin.get();
    return 0;
}
