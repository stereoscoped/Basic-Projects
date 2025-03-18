#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <iomanip>


int main() {
    std::string words[6] = {"hello","bye","snake","herrrmm","bruooo","duh"};
    char guess = ' ';
    int guessNumber = 1;
    int incorrectCount = 0;
    int correctCount = 0;
    int incorrectLimit = 8;
    char incorrectLetters[50];

    srand(time(0));
    int chosenWordIndex = rand()%size(words);
    char * word = new char[words[chosenWordIndex].size()];
    strcpy(word, words[chosenWordIndex].c_str());

    int correctIndex[strlen(word)];
    for (int i = 0; i < strlen(word); ++i) {
        correctIndex[i] = 0;
    }

    for (int i = 0; i < strlen(word); ++i) {
        std::cout << '_';
    }
    std::cout << std::endl;
    while ((incorrectCount < incorrectLimit) && (correctCount < strlen(word))) {
        bool incorrect = true;
        std::cout << "Guess " << guessNumber << " >> ";
        std::cin >> guess;
        for (int i = 0; i < strlen(word); ++i) {
            if (guess == word[i]) {
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

        for (int j = 0; j < strlen(word); ++j) {
            if (correctIndex[j] == 1) {
                std::cout << word[j];
            } else {
                std::cout << '_';
            }
        }
        // Print top border
        std::cout << std::endl << "+------------------------+" << std::endl;

        // Print the incorrect letters inside the box
        std::cout << "| ";
        
        // Generate the content with spaces
        std::string content;
        for (int i = 0; i < strlen(incorrectLetters); ++i) {
            content += incorrectLetters[i];
            content += " ";
        }

        // Calculate padding for right alignment
        int padding = 24 - content.length();

        // Print the content left-aligned with padding on the right
        std::cout << std::left << std::setw(23) << content << "|" << std::endl;

        // Print bottom border
        std::cout << "+------------------------+" << std::endl;

    }
    for (int i = 0; i < strlen(word); ++i) {
        std::cout << correctIndex[i];
    }
    delete[] word;
    return 0;
}