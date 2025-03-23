#include "functions.h"
#include "loadgraphics.h"

int main() {

    // Checks if files are in the same directory
    std::ifstream inFile("basic_english_2000.txt");
    if (!inFile) {
        std::cerr << "Error opening english file." << std::endl;
        return 1;
    }
    std::ifstream hangmanFile("hangman.txt");
    if (!hangmanFile) {
        std::cerr << "Error opening hangman.txt file." << std::endl;
        return 1;
    }

    // Loads hangman graphics
    int stages, lineCount;
    std::string **hangmanText;
    loadHangmanGraphics(hangmanFile, stages, lineCount, hangmanText);
    int incorrectLimit = stages - 1; 

    // Loads words from file into string array
    int totalLineCount = 0;
    std::string *words;
    loadWords(totalLineCount, inFile, words);

    // Big loop
    welcome();
    char choice = 'Y';
    while (toupper(choice) != 'N') {
        // Guesses and count declaration 
        char guess = ' ';
        int guessNumber = 1;
        int incorrectCount = 0;
        int correctCount = 0;
        char incorrectLetters[incorrectLimit] = {0};

        // Chooses the word from the file
        srand(time(0));
        int chosenWordIndex = rand()%totalLineCount;
        char * word = new char[words[chosenWordIndex].size()];
        strcpy(word, words[chosenWordIndex].c_str());

        // Sets the correct index, which determines which letters are correct
        int correctIndex[strlen(word)];
        for (int i = 0; i < strlen(word); ++i) {
            correctIndex[i] = 0;
        }
        display(word, correctIndex, hangmanText, incorrectCount, lineCount, incorrectLetters, incorrectLimit);

        // Loop guesses - Breaks either on win or loss
        while ((incorrectCount < incorrectLimit) && (correctCount < strlen(word))) {
            bool incorrect = true;
            std::cout << "\nGuess " << guessNumber << " >> ";
            std::cin >> guess;

            // Checks for each letter in the word
            for (int i = 0; i < strlen(word); ++i) {

                // If there is a correct letter in the word
                if (guess == word[i]) {

                    // Check if it has been found already
                    if (correctIndex[i] != 1) {
                        if (incorrect) {
                            std::cout << "\nCorrect Letter!" << std::endl;
                        }
                        correctIndex[i] = 1;
                        ++correctCount;
                    } else {
                        if (incorrect) {
                            std::cout << "\nYou already guessed the letter " << guess << std::endl;
                        }
                    }
                    incorrect = false;
                }
            }
            if (incorrect) {
                // Checks if found already (in hard mode, this will increase incorrect letter count)
                bool repeat = false;
                for (int i = 0; i < strlen(incorrectLetters); ++i) {
                    if (guess == incorrectLetters[i]) {
                        repeat = true;
                    }
                }
                if (!repeat) {
                    std::cout << "\nIncorrect Letter!" << std::endl;
                    strncat(incorrectLetters, &guess, 1);

                    ++incorrectCount;
                } else {
                    std::cout << "\nYou already guessed the letter " << guess << std::endl;
                }
            }
            ++guessNumber;
            display(word, correctIndex, hangmanText, incorrectCount, lineCount, incorrectLetters, incorrectLimit);
        }
        // While loop breaks on either win or loss, so conditional below determines it
        if (!(correctCount < strlen(word))) {
            std::cout << "\nYou won!" << std::endl;
        } else {
            std::cout << "\nYou lost! The word was " << word << std::endl;
        }

        delete[] word;
        std::cout << "\nPlay again? (Y/N) >> ";
        std::cin >> choice;
        while ((toupper(choice) != 'Y' && toupper(choice) != 'N') || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid option! Please choose Y or N >> ";
            std::cin >> choice;
        }
    }
    std::cout << "\nThank you for playing!" << std::endl;
    cleanup(hangmanText, stages, words);
    return 0;
}