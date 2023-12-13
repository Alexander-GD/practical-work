#include <span>
#include <string>

/**
 * @brief Launch the game "What? Where? When?".
 */
void startWhatWhereWhenGame();

/**
 * @brief Prints the number of points to the console.
 * @param playerPoints Player points.
 * @param viewerPoints Viewer points.
 */
void showNumberOfPoints(const unsigned playerPoints, const unsigned viewerPoints);

/**
 * @brief Select a sector relative to the current one.
 * @param sectorNumber Number of the current sector that will be replaced with a new one.
 * @param sectors      Sector list.
 */
void chooseSector(unsigned& sectorNumber, std::span<bool> sectors);

/**
 * @brief Print a question from the specified sector to the console.
 * @param pathQuestion Path to the question file.
 * @param sectorNumber Current sector number.
 */
void showQuestion(const std::string& pathQuestion, const unsigned sectorNumber);

/**
 * @brief Check the correctness of the player's answer.
 * @param pathAnswer Path to the file containing the sector answer.
 * @param answer     Player's answer.
 * @return True if the player's answer is correct otherwise false.
 */
bool checkAnswer(const std::string& pathAnswer, std::string answer);

/**
 * @brief Get the user's answer to a sector question.
 * @param msg The message will be printed before user input.
 * @return Answer from the user.
 */
std::string getAnswerFromUser(const std::string& msg);

/**
 * @brief Get the sector offset value from the user.
 * @param msg The message will be printed before user input.
 * @return Offset value from the user.
 */
unsigned getOffsetFromUser(const std::string& msg);
