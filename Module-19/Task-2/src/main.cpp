#include <fstream>
#include <iostream>

using namespace std;

// Prints the contents of a file to the console.
// Returns true if the file was successfully opened, otherwise false.
bool fileViewer(const string& filePath, const unsigned chunkSize = 50);

// Get the file path from the user.
string getFilePathFromUser(const string& msg);


int main()
{
    cout << "Task 19.2 Development of a text file viewer\n"
         << "----------------------------------------------\n\n";

    string filePath = getFilePathFromUser("Enter file path: ");
    fileViewer(filePath);

    cin.get();
    return 0;
}

bool fileViewer(const string& filePath, const unsigned chunkSize)
{
    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file \"" << filePath << "\"\n";
        return false;
    }

    cout << '\n';
    for (string buffer(chunkSize, '\0'); file;) 
    {
        file.read(buffer.data(), chunkSize);
        if (file.eof())
            buffer.erase(file.gcount());

        cout << buffer;
    }

    file.close();
    return true;
}

string getFilePathFromUser(const string& msg)
{
    string input;
    while (true) {
        cout << msg;
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start == string::npos)
            cerr << "Error: Invalid input\n\n";
        else
            return input.substr(start, last - start + 1);
    }
}
