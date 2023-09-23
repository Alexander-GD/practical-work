#include <iostream>

#include "console/user_input.hpp"
#include "game/bubble_wrap.hpp"

using namespace std;

int main()
{
    cout << "Task 14.5 Bubble wrap (Pupyrka).\n"
         << "-----------------------------------\n\n";

    startPoppingBubbleWrap();

    preventConsoleClosing();
    return 0;
}
