#include "commands.hpp"

#include <iostream>
#include "platforms.hpp"

using namespace std;

void clearConsole()
{
    cout << "\033[2J\033[H\033[3J";
};

string clearLine(const unsigned number)
{
    return (number == 0) ? "\033[2K\r" : "\033[" + to_string(number) + "A\033[2K\r";
};

string clearLines(const unsigned number)
{
    return "\033[" + to_string(number) + "A\033[J";
};

string colorize(const string text, const string colorCode, const string resetCode)
{
    return string{"\033[" + colorCode + "m" + text + "\033[" + resetCode + "m"};
};
