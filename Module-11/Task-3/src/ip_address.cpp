#include "ip_address.hpp"

using namespace std;

string getOctetOfIpAddress(const string address, const int octetNo)
{
    string result;

    if (address.length() > 0 && (0 <= octetNo && octetNo <= 3))
    {
        int dots = 0;
        for (size_t i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
            {
                dots++;
            }
            else if (dots == octetNo)
            {
                result += address[i];
            }
            else if (dots == octetNo + 1)
            {
                break;
            }
        }

        if (dots == 0)
            result.clear();
    }

    return result;
}

bool isOctetOfIpAddressValid(const string octet)
{
    const size_t lenght = octet.length();

    // the octet must contain 1 to 3 characters
    if (lenght == 0 || lenght > 3)
        return false;

    // the octet must consist of digits
    for (size_t i = 0; i < lenght; i++)
    {
        if (octet[i] < '0' || '9' < octet[i])
            return false;
    }

    // the octet must not contain leading zeros (01, 010, 001, 00, 000)
    if (octet[0] == '0' && lenght >= 2)
        return false;

    // the octet must not exceed 255
    if ((lenght == 3 && octet[0] == '2' && octet[1] > '5') || (octet[1] == '5' && octet[2] > '5'))
        return false;

    return true;
}

bool isIpAddressValid(const string address)
{
    // IP address must not be empty
    if (address.length() == 0)
        return false;

    // number of dots in ip address
    int dots = 0;
    for (size_t i = 0; i < address.length() && dots <= 3; i++)
    {
        if (address[i] == '.')
            dots++;
    }

    // the number of separating dots in the ip address must be 3
    if (dots != 3)
        return false;

    // each octet in the IP address must be numbers and must be in the range 0 to 255
    string octet;
    for (size_t i = 0; i <= 3; i++)
    {
        octet = getOctetOfIpAddress(address, i);
        if (!isOctetOfIpAddressValid(octet))
            return false;
    }

    return true;
}
