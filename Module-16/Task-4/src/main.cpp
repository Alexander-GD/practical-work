#include <iostream>
#include "piano.hpp"

using namespace std;

main()
{
     cout << "Task 16.4 Mechanical piano\n"
          << "-----------------------------\n\n";

     unsigned melody[12];
     cout << "Enter 12 combinations of notes (1 to 7)\n\n";
     
     for (size_t i = 0; i < 12; i++)
     {
          string notes = getNotesFromUser((to_string(i + 1) + ") "));
          melody[i]    = notesToChord(notes);
     }

     cout << "\nMelody:\n\n";
     printMelody(melody, 12);

     cin.get();
     return 0;
}
