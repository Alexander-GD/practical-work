#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

// Get the type of fish from the user
string getFishTypeFromUser();

int main()
{
    cout << "Task 20.3 Fishing game simulation\n"
         << "------------------------------------\n\n";

    string filePathRiver("data/river.txt");
    string filePathBasket("basket.txt");

    ifstream river(filePathRiver);
    ofstream basket(filePathBasket, ios::app);

    if (!river || !basket) {
        cerr << "Error: Failed to open file \"" << ((river) ? filePathBasket : filePathRiver) << "\"";
        cin.get();
        return EXIT_FAILURE;
    }

    unsigned totalFish = 0;
    string   caughtFish;
    string   targetFish = getFishTypeFromUser();

    for (string fish; getline(river, fish);) {
        transform(fish.begin(), fish.end(), fish.begin(), ::tolower);

        if (fish.find(targetFish) != string::npos) {
            caughtFish.append(fish + "\n");
            totalFish++;
        }
    }

    cout << "\nTotal fish caught in the river: " << totalFish << '\n';

    if (!basket.write(caughtFish.data(), static_cast<streamsize>(caughtFish.size())))
        cerr << "\nError: Failed to write data to file \"" << filePathBasket << "\"\n";

    river.close();
    basket.close();

    cin.get();
    return 0;
}

string getFishTypeFromUser()
{
    string input;
    while (true) {
        cout << "Enter the type of fish you want to catch (e.g. bass, carp, salmon): ";
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start != string::npos) {
            input = input.substr(start, last - start + 1);

            if (none_of(input.begin(), input.end(), ::isspace) && 
                all_of(input.begin(), input.end(), ::isalpha))
            {
                transform(input.begin(), input.end(), input.begin(), ::tolower);
                return input;
            }
        }
        cerr << "Error: Invalid input\n\n";
    }
}
