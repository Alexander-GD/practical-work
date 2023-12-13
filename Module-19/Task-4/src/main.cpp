#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>

using namespace std;

// Check if file is a PNG image.
bool isValidPngFile(const string& file);

// Get the file path from the user.
string getFilePathFromUser(const string& msg);


int main()
{
    cout << "Task 19.4 Development of a PNG file detector\n"
         << "-----------------------------------------------\n\n";

    string filePath = getFilePathFromUser("Enter file path: ");

    if (isValidPngFile(filePath))
        cout << "\nThis is a PNG image!\n";
    else
        cout << "\nThe file is not a PNG image!\n";

    cin.get();
    return 0;
}

bool isValidPngFile(const string& filePath)
{
    size_t pos = filePath.rfind(".");
    if (pos == string::npos) // file without extension
        return false;

    string extension = filePath.substr(pos + 1);
    transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    if (extension.compare("png") != 0)
        return false;

    ifstream pngFile(filePath, ios::binary);
    if (!pngFile.is_open()) {
        cerr << "\nError: Failed to open file \"" << filePath << "\"\n";
        cin.get();
        exit(EXIT_FAILURE);
    }

    array<char, 4> pngSignature{-0x77, 0x50, 0x4e, 0x47}; // valid PNG signature
    array<char, 4> curentSignature;

    pngFile.read(curentSignature.begin(), curentSignature.size());
    pngFile.close();

    return equal(curentSignature.begin(), curentSignature.end(), pngSignature.begin());
}

string getFilePathFromUser(const string& msg)
{
    string input;
    while (true) {
        cout << msg;
        getline(cin, input);

        size_t start = input.find_first_not_of(" \'\"");
        size_t last  = input.find_last_not_of(" \'\"");

        if (start == string::npos)
            cerr << "Error: Invalid input\n\n";
        else
            return input.substr(start, last - start + 1);
    }
}
