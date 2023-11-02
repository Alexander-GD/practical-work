#include <iostream>
#include "algorithm.hpp"

using namespace std;

int main()
{
     cout << "Task 15.1\n"
          << "------------\n\n";

     vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

     int    maxSum;
     size_t begin[]{0};
     size_t end[]{0};

     maxSum = maxSubarraySum(numbers, begin, end);

     cout << "The greatest sum of consecutive elements is " << maxSum
          << " and is between indices " << begin[0] << " and " << end[0] << endl;

     cin.get();
     return 0;
}
