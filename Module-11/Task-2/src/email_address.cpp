#include "email_address.hpp"

using namespace std;

bool consistsOfCharacters(const string str, const string characters)
{
    bool result = true;
    for (size_t i = 0; i < str.length(); i++)
    {
        result = false;
        for (size_t j = 0; j < characters.length(); j++)
        {
            if (str[i] == characters[j])
            {
                result = true;
                break;
            }
        }

        if (result == false)
            break;
    }

    return result;
}

string getLocalPartOfEmailAddress(const string address)
{
    string result;

    if (address.find('@') != string::npos)
    {
        // get all characters up to '@'
        for (size_t i = 0; (i < address.length()) && (address[i] != '@'); i++)
        {
            result += address[i];
        }
    }

    return result;
}

string getDomainPartOfEmailAddress(const string address)
{
    string result;
    bool splitCharacter = false;  // @

    // get all characters after the first '@'
    for (size_t i = 0; i < address.length(); i++)
    {
        if (splitCharacter)
        {
            result += address[i];
        }
        else if (address[i] == '@')
        {
            splitCharacter = true;
        }
    }

    return result;
}

bool isValidEmailAddress(const string address)
{
    const string localPart  = getLocalPartOfEmailAddress(address);
    const string domainPart = getDomainPartOfEmailAddress(address);

    // the local and domain parts of the email address are of the correct length
    if ((localPart.length()  < 1 || 64 < localPart.length()) ||
        (domainPart.length() < 1 || 63 < domainPart.length()))
    {
        return false;
    }

    // the local and domain parts of an email address do not start or end with a dot
    if ((localPart[0]  == '.' || localPart[(localPart.length() - 1)] == '.') ||
        (domainPart[0] == '.' || domainPart[(domainPart.length() - 1)] == '.'))
    {
        return false;
    }

    // the email address does not contain a sequence of multiple dots
    for (size_t sequenceDots = 0, i = 0; i < address.length(); i++)
    {
        sequenceDots = (address[i] == '.') ? (sequenceDots + 1) : 0;
        if (sequenceDots > 1)
            return false;
    }
    
    string validCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-";

    // the domain-part must contain only valid characters
    if (!consistsOfCharacters(domainPart, validCharacters))
        return false;

    validCharacters += "!#$%&'*+-/=?^_`{|}~";

    // the local-part must contain only valid characters
    if (!consistsOfCharacters(localPart, validCharacters))
        return false;

    return true;
}
