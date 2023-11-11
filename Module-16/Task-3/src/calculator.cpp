#include "calculator.hpp"
#include <sstream>

bool calculator(const std::string expression, double result[])
{
    double number1;
    double number2;
    char   operation;
    double calculation;

    std::stringstream ss(expression);

    if ((ss >> std::noskipws >> number1 >> operation >> number2).fail() || !ss.eof())
        return false;

    if (operation == '+')
        calculation = number1 + number2;
    else if (operation == '-')
        calculation = number1 - number2;
    else if (operation == '/')
    {
        if (number2 == 0) return false;
        calculation = number1 / number2;
    }
    else if (operation == '*')
        calculation = number1 * number2;
    else
        return false;

    if (result != nullptr)
        result[0] = calculation;

    return true;
}
