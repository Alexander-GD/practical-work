#include "piano.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

// The notes presented as unique bit masks
enum Note : unsigned
{
    DO  = 1,
    RE  = 2,
    MI  = 4,
    FA  = 8,
    SOL = 16,
    LA  = 32,
    SI  = 64
};

bool isValidNotes(const string notes)
{
    unsigned currentNotes = 0;
    unsigned note = 0;

    for (char number : notes)
    {
        note = Note::DO << ((number - '0') - 1); // convert note number to note bitmask

        if (number == '0' || number == '8' || number == '9' || (currentNotes & note) != 0)
            return false;

        currentNotes |= note; // save the current note bit to check for repeating
    }
    return true;
}

unsigned notesToChord(const string notes)
{
    unsigned chord = 0;
    for (char note : notes)
        chord |= Note::DO << ((note - '0') - 1);

    return chord;
}

string chordsToLinesOfNotes(const unsigned chord)
{
    string linesOfNotes;

    if (chord & Note::DO)  linesOfNotes += "DO ";
    if (chord & Note::RE)  linesOfNotes += "RE ";
    if (chord & Note::MI)  linesOfNotes += "MI ";
    if (chord & Note::FA)  linesOfNotes += "FA ";
    if (chord & Note::SOL) linesOfNotes += "SOL ";
    if (chord & Note::LA)  linesOfNotes += "LA ";
    if (chord & Note::SI)  linesOfNotes += "SI ";

    return linesOfNotes;
}

string getNotesFromUser(const string msg)
{
    string input;
    while (true)
    {
        cout << msg;
        getline(cin, input);

        if (input.length() == 0 || input.length() > 7 ||
            !all_of(input.cbegin(), input.cend(), ::isdigit) ||
            !isValidNotes(input))
        {
            cerr << "Error: Invalid input\n\n";
        }
        else break;
    }
    return input;
}

void printMelody(unsigned melody[], const size_t size)
{
    for (size_t i = 0; i < size; i++)
        cout << chordsToLinesOfNotes(melody[i]) << "\n";
}
