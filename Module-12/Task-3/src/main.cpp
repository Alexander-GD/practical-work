#include <iostream>
#include <cassert>

using namespace std;

float travelTime(float distance, float speed);

int main()
{
    cout << "Task 12.3 Using the assert.\n";
    cout << "------------------------------\n\n";

    travelTime(100.0f, 0);  // check the operation of the assert macro

    return 0;
}

float travelTime(float distance, float speed)
{
    assert(distance >= 0 && "Whoops, distance can't possibly be negative!");
    assert(speed > 0     && "Whoops, speed can't be negative or zero!");
    return distance / speed;
}
