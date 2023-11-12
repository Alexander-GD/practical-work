#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    cout << "Task 17.1\n"
         << "------------\n\n";

    int a = 10;
    int b = 20;

    swap(&a, &b);

    cout << "a = " << a << "\n"
         << "b = " << b << endl;

    cin.get();
    return 0;
}
