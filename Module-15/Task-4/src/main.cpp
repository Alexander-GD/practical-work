#include <iostream>
#include "algorithm.hpp"

using namespace std;

int main()
{
     cout << "Task 15.4\n"
          << "------------\n\n";

     vector<int> numbers = {-100, -50, -5, 1, 10, 15};

     PrintArrayInOrderOfModule(numbers);

     cin.get();
     return 0;
}
