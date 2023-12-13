#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

// Count the occurrences of a specific word in a text file. The search is case-insensitive,
// If the file cannot be opened, it returns -1.
int countWordOccurrences(const string& filePath, string targetWord);

// Get word from user.
string getWordFromUser(const string& msg);


int main()
{
    cout << "Task 19.1 Word search program in file\n"
         << "----------------------------------------\n\n";

    string filePath = "data/words.txt";
    string word     = getWordFromUser("Enter a word: ");
    int    result   = countWordOccurrences(filePath, word);

    if (result != -1)
        cout << "\nWords found: " << result << endl;

    cin.get();
    return 0;
}

int countWordOccurrences(const string& filePath, string targetWord)
{
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file \"" << filePath << "\"\n";
        return -1;
    }

    int count = 0;
    transform(targetWord.begin(), targetWord.end(), targetWord.begin(), ::tolower);

    for (string token; file >> token;) {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        if (token == targetWord)
            count++;
    }

    file.close();
    return count;
}

string getWordFromUser(const string& msg)
{
    string input;
    while (true) {
        cout << msg;
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start == string::npos || any_of(input.data() + start, input.data() + last + 1, ::isspace))
            cerr << "Error: Invalid input\n\n";
        else
            return input.substr(start, last - start + 1);
    }
}
