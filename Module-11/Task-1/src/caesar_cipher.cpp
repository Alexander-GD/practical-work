#include "caesar_cipher.hpp"

using namespace std;

string encryptCaesar(string text, int key)
{
    int sizeAlphabet = 26;

    if (key == 0 || key == sizeAlphabet || text.length() == 0)
        return text;

    if (key < 0) 
        key = sizeAlphabet + key % sizeAlphabet;

    for (size_t i = 0; i < text.length(); i++)
    {
        if ('A' <= text[i] && text[i] <= 'Z')
        {
            text[i] = 'A' + (text[i] - 'A' + key) % sizeAlphabet;
        }
        else if ('a' <= text[i] && text[i] <= 'z')
        {
            text[i] = 'a' + (text[i] - 'a' + key) % sizeAlphabet;
        }
    }
    return text;
}

string decryptCaesar(string text, int key)
{
    return encryptCaesar(text, -key);
}
