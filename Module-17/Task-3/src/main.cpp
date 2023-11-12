#include <iostream>
#include <cstring>

using namespace std;

bool substr(const char *str, const char *subStr)
{
    return strstr(str, subStr);
}

int main()
{
    cout << "Task 17.3\n"
         << "------------\n\n";

    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    cout << boolalpha << substr(a, b) << " " << substr(a, c) << endl;

    cin.get();
    return 0;
}
