#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

bool   isNumber(const string str);
string GetNumberFromUser(const string msg, bool enableSign = true);

int main()
{
     cout << "Task 16.2 Combine the parts of a fraction\n"
          << "--------------------------------------------\n\n";

     string wholeNumber;
     string fractionalPart;

     wholeNumber    = GetNumberFromUser("Enter the whole part of a decimal number: ");
     fractionalPart = GetNumberFromUser("Enter the fractional part of a decimal number: ", false);

     double number = stod((wholeNumber + "." + fractionalPart));

     cout << "\nFloating point number: " << setprecision(17) << number << endl;

     cin.get();
     return 0;
}

bool isNumber(const string str)
{
     return (str.length() > 0 &&
             (isdigit(str.front()) || (str.length() > 1 && str.front() == '-')) &&
             all_of(str.cbegin() + 1, str.cend(), ::isdigit));
}

string GetNumberFromUser(const string msg, bool enableSign)
{
     string input;
     while (true)
     {
          cout << msg;
          getline(cin, input);

          if (isNumber(input) && (enableSign || (!enableSign && input.front() != '-')))
               break;
          else
               cerr << "Error: Invalid input\n\n";
     }
     return input;
}
