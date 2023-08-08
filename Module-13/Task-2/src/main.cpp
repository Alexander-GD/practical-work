#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void preventConsoleClosing();

int main()
{
    cout << "Task 13.2\n";
    cout << "------------\n\n";

    vector<float> prices {2.52, 4.25, 3.0, 10.0, 29.99};
    vector<size_t> items {1, 1, 10, 3, 4, 8};

    float totalCost = 0;
    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i] < prices.size())
            totalCost += prices[items[i]];
        else
            cout << "No item with index " << items[i] << '\n';
    }

    cout << "\nThe total cost is: " << totalCost << endl;

    preventConsoleClosing();
    return 0;
}

void preventConsoleClosing()
{
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cin.get();
}
