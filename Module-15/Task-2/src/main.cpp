#include <iostream>
#include <algorithm>
#include "algorithm.hpp"

using namespace std;

int main()
{
     cout << "Task 15.2\n"
          << "------------\n\n";

     vector<int> numbers = {2, 7, 11, 15};

     int first []{0};
     int second[]{0};
     int target = 9;

     // Before using the findPairWithGivenSum function, the array must be sorted ascending.
     std::sort(numbers.begin(), numbers.end()); // O(n·log(n))

     if (findPairWithGivenSum(numbers, target, first, second))
          cout << "The pair whose sum is " << target << " are: " << first[0] << " and " << second[0] << endl;
     else
          cout << "No pairs found with sum " << target << endl;

     cin.get();
     return 0;
}
