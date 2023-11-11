#pragma once
#include <string>

/**
 * @brief The notes are correct.
 * @param notes A string containing note numbers from 1 to 7.
 * @return True if the notes are correct, otherwise false.
 */
bool isValidNotes(const std::string notes);

/**
 * @brief Converts a string of notes as numbers to a chord as a number containing the unique bits of each note.
 * @param notes A string containing note numbers from 1 to 7.
 * @return Number containing the unique bits of the notes.
 */
unsigned int notesToChord(const std::string notes);

/**
 * @brief Converts a chord containing note bits into a string list of note names, separated by spaces.
 * @param chord Number containing the unique bits of the notes.
 * @return A string consisting of note names separated by spaces.
 */
std::string chordsToLinesOfNotes(const unsigned chord);

/**
 * @brief Get user input list of note numbers.
 *        Until the user enters valid input, the error message "Error: Invalid Input" will be displayed.
 * @param msg This message will be printed to the console before user input.
 * @return A string containing note numbers from 1 to 7.
 */
std::string getNotesFromUser(const std::string msg);

/**
 * @brief Print a melody consisting of chords to the console as a list of note names.
 * @param melody An array containing chords as strings of note names.
 * @param size   Array size.
 */
void printMelody(unsigned melody[], const size_t size);
