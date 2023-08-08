#include "user_input.hpp"

#include <iostream>
#include <limits>

using namespace std;

int getNumericUserInput(const string msg, const int low, const int high)
{
    int input;
    cout << msg;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.peek() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Error: Invalid input.\n\n" << msg;
    }
    cin.ignore();
    return input;
}

unsigned getPositiveNumericUserInput(const string msg, const unsigned low, const unsigned high)
{
    unsigned input;
    cout << msg;
    while (cin.peek() == '-' || (cin >> noskipws >> input >> skipws).fail() || cin.peek() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Error: Invalid input.\n\n" << msg;
    }
    cin.ignore();
    return input;
}

float getFloatingPointNumericUserInput(const string msg, const float low, const float high)
{
    float input;
    cout << msg;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.peek() != '\n' ||
           input < low || input > high)
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Error: Invalid input.\n\n" << msg;
    }
    cin.ignore();
    return input;
}

string getStringUserInput(const string msg)
{
    string input;
    cout << msg;
    while ((cin >> noskipws >> input >> skipws).fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Error: Invalid input.\n\n" << msg;
    }
    cin.ignore();
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
            (cin.peek()  != ' '  && cin.peek() != '\n') ||
            (cin.peek()  == '\n' && size != 0  && sequence.size() != size - 1) ||
            (input < low || input > high))
        {
            sequence.clear();
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cout << "Error: Invalid input.\n\n" << msg;
        }
        else
        {
            sequence.push_back(input);
            if (cin.peek() == '\n') break;
            cin.get();
        }
    }
    cin.ignore();
    return sequence;
}

void preventConsoleClosing()
{
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cin.get();
}
