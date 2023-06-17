#include <iostream>
#include <limits>

#include "caesar_cipher.hpp"

using namespace std;

int getNumericUserInput(const string msg);

int main()
{
    string text;
    int key = 0;

    cout << "Task 11.1 The Caesar Cipher.\n";
    cout << "-------------------------------\n\n";

    cout << "Encryption!\n";
    cout << "Input the text: ";
    getline(cin, text);
    key = getNumericUserInput("\nInput the key: ");
    cout << "\nCipher text: " << encryptCaesar(text, key);

    cout << "\n-------------------------------\n\n";

    cout << "Decryption!\n";
    cout << "Input the text: ";
    getline(cin, text);
    key = getNumericUserInput("\nInput the key: ");
    cout << "\nDeciphered text: " << decryptCaesar(text, key) << endl;

    // Prevent console closing.
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cin.get();
    return 0;
}

int getNumericUserInput(const string msg)
{
    int input;
    while (true)
    {
        cout << msg;
        cin  >> input;
        if ((cin.fail() || cin.peek() != '\n'))
        {
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            cerr << "\nError! Wrong input.\n";
        }
        else
        {
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            break;
        }
    }
    return input;
}
