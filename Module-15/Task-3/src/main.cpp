#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    cout << "Task 15.3\n"
         << "------------\n\n"
         << "Commands:\n"
         << " [-1] output the fifth largest number\n"
         << " [-2] ending the program\n\n"
         << "Enter a sequence of integers:\n";

    int input = 0;
    vector<int> numbers;
    vector<int> buffer;

    while (input != -2)
    {
        cout << "\n> ";
        while (true)
        {
            if ((cin >> noskipws >> input >> skipws).fail() ||
                (cin.peek() != ' ' && cin.peek() != '\n'))
            {
                cin.clear();
                cerr << "Error: Invalid input.\n";
                break;
            }
            else if (input == -1)
            {
                numbers.insert(numbers.cend(), buffer.cbegin(), buffer.cend());
                if (numbers.size() >= 5)
                {
                    sort(numbers.begin(), numbers.end());
                    cout << "\n" << numbers[4] << " (fifth largest number)\n";
                }
                else
                    cerr << "\nNot enough numbers!\n";

                break;
            }
            else if (input == -2)
            {
                cout << "\nThe program is finished!\n";
                break;
            }
            else
            {
                buffer.push_back(input);
                if (cin.peek() == '\n')
                {
                    numbers.insert(numbers.cend(), buffer.cbegin(), buffer.cend());
                    break;
                }
                cin.get();
            }
        }

        buffer.clear();
        if (cin.get() != '\n')
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }

    cin.get();
    return 0;
}
