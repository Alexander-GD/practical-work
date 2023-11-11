#include <iostream>
#include <iomanip>
#include "calculator.hpp"

using namespace std;

int main()
{
     cout << "Task 16.3 Calculator\n"
          << "-----------------------\n\n";

     double result[1];
     string input;

     while (true)
     {
          cout << "Enter a mathematical expression (no spaces): ";
          getline(cin, input);

          if (!calculator(input, result))
               cerr << "Error: Invalid input\n\n";
          else
          {
               cout << "\nResult: " << setprecision(17) << result[0] << endl;
               break;
          }
     }

     cin.get();
     return 0;
}
