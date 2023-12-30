#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;

// Get statement data from the user.
string getStatementDataFromUser();

// Is the date valid.
bool isValidDate(const tm& date);

// Remove extra spaces from a line.
void removeExcessSpaces(string& str);

int main()
{
    cout << "Task 20.1 Entry on account statement\n"
         << "---------------------------------------\n\n";

    string   filePath{"statement.txt"};
    ofstream statement(filePath, ios::app);

    if (!statement) {
        cerr << "Error: Failed to open file \"" << filePath << "\"\n";
        cin.get();
        return EXIT_FAILURE;
    }

    cout << "Enter the data to be recorded in the statement or 0 to exit:\n"
         << "(name surname date(dd.mm.yyyy) payment_amount)\n\n";

    for (string data; (data = getStatementDataFromUser()) != "0";) {
        if ((statement << data << '\n').fail()) {
            statement.close();
            cerr << "Error: Failed to write data to file \"" << filePath << "\"\n";
            cin.get();
            return EXIT_FAILURE;
        }
    }

    statement.close();
    cin.get();
    return 0;
}

string getStatementDataFromUser()
{
    string        input; // Tom Hanks 01.03.2020 35500
    istringstream iss;

    while (true) {
        cout << "> ";
        getline(cin, input);
        removeExcessSpaces(input);

        if (input == "0")
            return input;

        string name;
        string surname;
        tm     date;
        string payout;

        iss.str(input);
        iss >> name >> surname >> get_time(&date, "%d.%m.%Y") >> payout;

        if (iss && iss.eof() && all_of(name.begin(), name.end(), ::isalpha) &&
            all_of(surname.begin(), surname.end(), ::isalpha) &&
            all_of(payout.begin(), payout.end(), ::isdigit) &&
            isValidDate(date)) {
            return input;
        }

        cerr << "Error: Invalid input\n\n";
        iss.clear();
    }
}

bool isValidDate(const tm& date)
{
    unsigned day   = static_cast<unsigned>(date.tm_mday);
    unsigned month = static_cast<unsigned>(date.tm_mon + 1);
    int      year  = date.tm_year + 1900;

    return chrono::year_month_day(chrono::year(year), chrono::month(month), chrono::day(day)).ok();
}

void removeExcessSpaces(string& str)
{
    size_t pos = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != ' ' || (pos != 0 && str[i - 1] != ' '))
            str[pos++] = str[i];
    }
    str.erase(string::iterator(&str[pos - (str[pos - 1] == ' ')]), str.end());
}
