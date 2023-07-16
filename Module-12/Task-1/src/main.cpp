#include <iostream>

using namespace std;

int getNumericUserInput(const string msg);
string getStringUserInput(const string msg);
void preventConsoleClosing();

int main()
{
    cout << "Task 12.1 Apartment house.\n";
    cout << "-----------------------------\n\n";

    string lastName[10];
    for (size_t i = 0; i < 10; i++)
        lastName[i] = getStringUserInput("Enter last name: ");

    cout << "\n-----------------------------\n";
    for (int i = 0; i < 3;)
    {
        int number = getNumericUserInput("Enter the apartment number from 1 to 10: ");
        if (1 <= number && number <= 10)
        {
            cout << lastName[number - 1] << endl;
            i++;
        }
        else
            cout << "Incorrect apartment number!\n\n";
    }

    preventConsoleClosing();
    return 0;
}

int getNumericUserInput(const string msg)
{
    int input;
    while (true)
    {
        cout << msg;
        cin  >> input;
        if ((cin.fail() || cin.peek() != '\n'))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cerr << "Error! Wrong input.\n\n";
        }
        else
            break;
    }
    cin.ignore(INT_MAX, '\n');
    return input;
}

string getStringUserInput(const string msg)
{
    string input;
    while (true)
    {
        cout << msg;
        getline(cin, input);
        bool isValidInput = true;

        for (size_t i = 0; i < input.length() && isValidInput; i++)
            if (isalpha(input[i]) == 0)
                isValidInput = false;

        if (input.length() <= 1 || isValidInput == false)
            cerr << "Error! Wrong input.\n\n";
        else
            break;
    }
    return input;
}

void preventConsoleClosing()
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cin.get();
}
