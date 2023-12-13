#include "what_where_when.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

void startWhatWhereWhenGame()
{
    const unsigned maxPoints    = 6; // Winning number of points
    const unsigned numOfSectors = 13;

    const string pathQuestion  = "data/questions/question_";
    const string pathAnswer    = "data/answers/answer_";
    const string fileExtension = ".txt";

    unsigned curentSector = 1;
    unsigned playerPoints = 0;
    unsigned viewerPoints = 0;

    array<bool, numOfSectors> sectors{}; // True - the sector played, false - did not play

    // The core gameplay loop
    while (playerPoints != maxPoints && viewerPoints != maxPoints) {
        showNumberOfPoints(playerPoints, viewerPoints);
        chooseSector(curentSector, sectors);
        showQuestion(pathQuestion + to_string(curentSector) + fileExtension, curentSector);

        string playerAnswer = getAnswerFromUser("Enter your answer: ");

        if (checkAnswer((pathAnswer + to_string(curentSector) + fileExtension), playerAnswer)) {
            cout << "\nCORRECT!\n";
            playerPoints++;
        } else {
            cout << "\nINCORRECT!\n";
            viewerPoints++;
        }
    }

    showNumberOfPoints(playerPoints, viewerPoints);
    cout << setw(28) << setfill(' ') << ((playerPoints == maxPoints) ? "Player" : "Viewer") << " wins!\n";
}

void showNumberOfPoints(const unsigned playerPoints, const unsigned viewerPoints)
{
    cout << "\n\n\tPlayer points: " << playerPoints << "\tViewer points: " << viewerPoints << '\n'
         << "   " << setw(52) << setfill('-') << "\n\n";
}

void chooseSector(unsigned& sectorNumber, span<bool> sectors)
{
    unsigned offset = getOffsetFromUser("Enter sector offset: ");
    sectorNumber    = (sectorNumber + offset - 1) % sectors.size() + 1;

    // Select a sector that has not played yet
    while (sectors[sectorNumber - 1])
        sectorNumber = sectorNumber % sectors.size() + 1;

    sectors[sectorNumber - 1] = true;
}

void showQuestion(const string& pathQuestion, const unsigned sectorNumber)
{
    ifstream file(pathQuestion);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file \"" << pathQuestion << "\"\n";
        cin.get();
        exit(EXIT_FAILURE);
    }

    cout << "\n[QUESTION SECTOR " << sectorNumber << "]: ";
    for (string question; getline(file, question);)
        cout << question << "\n\n";

    file.close();
}

bool checkAnswer(const string& pathAnswer, string answer)
{
    ifstream file(pathAnswer);
    if (!file.is_open()) {
        cerr << "Error: Failed to open file \"" << pathAnswer << "\"\n";
        cin.get();
        exit(EXIT_FAILURE);
    }

    string correctAnswer;
    file >> correctAnswer;
    file.close();

    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);

    return (answer == correctAnswer);
}

string getAnswerFromUser(const string& msg)
{
    string input;
    while (true) {
        cout << msg;
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start == string::npos || any_of(input.data() + start, input.data() + last + 1, ::isspace))
            cerr << "Error: Invalid input\n\n";
        else
            return input.substr(start, last - start + 1);
    }
}

unsigned getOffsetFromUser(const string& msg)
{
    string input;
    istringstream ss;

    while (true) {
        cout << msg;
        getline(cin, input);

        size_t start = input.find_first_not_of(' ');
        size_t last  = input.find_last_not_of(' ');

        if (start != string::npos && input[start] != '-') 
        {
            ss.str(input.substr(start, last - start + 1));
            if (unsigned offset; (ss >> offset) && ss.eof())
                return offset;

            ss.clear();
        }
        cerr << "Error: Invalid input\n\n";
    }
}
