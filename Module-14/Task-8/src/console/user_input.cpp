#include "user_input.hpp"

#include <iostream>
#include <limits>

#include "commands.hpp"

using namespace std;

int getNumericUserInput(const string msg, const int low, const int high)
{
    cout << msg;
    int input;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.get() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
    }
    cin.ignore();
    cout << clearLine();
    return input;
}

unsigned getPositiveNumericUserInput(const string msg, const unsigned low, const unsigned high)
{
    cout << msg;
    unsigned input;
    while (cin.peek() == '-' || (cin >> noskipws >> input >> skipws).fail() || cin.peek() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
    }
    cin.ignore();
    cout << clearLine();
    return input;
}

float getFloatingPointNumericUserInput(const string msg, const float low, const float high)
{
    cout << msg;
    float input;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.peek() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
    }
    cin.ignore();
    cout << clearLine();
    return input;
}

string getStringUserInput(const string msg)
{
    cout << msg;
    string input;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
    }
    cin.ignore();
    cout << clearLine();
    return input;
}

vector<int> getNumericSequenceOfUserInput(const string msg, const size_t size, const int low, const int high)
{
    cout << msg;
    int input;
    vector<int> sequence;
    while (true)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            (cin.peek() != ' '  && cin.peek() != '\n') ||
            (cin.peek() == '\n' && size != 0  && sequence.size() != size - 1) ||
            (input < low || input > high))
        {
            sequence.clear();
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
        }
        else
        {
            sequence.push_back(input);
            if (cin.get() == '\n') break;
        }
    }
    cout << clearLine();
    return sequence;
}

vector<float> getFloatNumberSequenceOfUserInput(const string msg, const size_t size, const float low, const float high)
{
    cout << msg;
    float input;
    vector<float> sequence;
    while (true)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            (cin.peek() != ' '  && cin.peek() != '\n') ||
            (cin.peek() == '\n' && size != 0  && sequence.size() != size - 1) ||
            (input < low || input > high))
        {
            sequence.clear();
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
        }
        else
        {
            sequence.push_back(input);
            if (cin.get() == '\n') break;
        }
    }
    cout << clearLine();
    return sequence;
}

void getNumericArrayOfUserInput(const std::string msg, int arr[], const size_t size, const int low, const int high)
{
    cout << msg;
    int input;
    for (size_t i = 1;;)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            ((i != size) && cin.peek() != ' ') ||
            ((i == size) && cin.peek() != '\n') ||
            (input < low || input > high))
        {
            i = 1;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
        }
        else
        {
            arr[i - 1] = input;
            if (cin.get() == '\n') break;
            i++;
        }
    }
    cout << clearLine();
}

void getPositiveNumericArrayOfUserInput(const std::string msg, unsigned arr[], const size_t size, const unsigned low, const unsigned high)
{
    cout << msg;
    unsigned input;
    for (size_t i = 1;;)
    {
        if (cin.peek() == '-' ||
            (cin >> noskipws >> input >> skipws).fail() ||
            ((i != size) && cin.peek() != ' ') ||
            ((i == size) && cin.peek() != '\n') ||
            (input < low || input > high))
        {
            i = 1;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
        }
        else
        {
            arr[i - 1] = input;
            if (cin.get() == '\n') break;
            i++;
        }
    }
    cout << clearLine();
}

void getFloatNumberArrayOfUserInput(const std::string msg, float arr[], const size_t size, const float low, const float high)
{
    cout << msg;
    float input;
    for (size_t i = 1;;)
    {
        if ((cin >> noskipws >> input >> skipws).fail() ||
            ((i != size) && cin.peek() != ' ') ||
            ((i == size) && cin.peek() != '\n') ||
            (input < low || input > high))
        {
            i = 1;
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << clearLine() << colorize("Error: Invalid input.\n", "3;31") << clearLine(2) << msg;
        }
        else
        {
            arr[i - 1] = input;
            if (cin.get() == '\n') break;
            i++;
        }
    }
    cout << clearLine();
}

void preventConsoleClosing()
{
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cin.get();
}
