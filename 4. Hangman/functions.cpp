#include "functions.h"

void display(char *word, int *correctIndex, std::string **hangmanText, int incorrectCount, int lineCount, char *incorrectLetters, int incorrectLimit){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "Guess the " << strlen(word) << " letter word: ";
    for (int j = 0; j < strlen(word); ++j) {
        if (correctIndex[j] == 1) {
            std::cout << word[j];
        } else {
            std::cout << '_';
        }
    }

    for (int j = 0; j < lineCount; ++j) {
        std::cout << std::endl << hangmanText[incorrectCount][j];
    }

    std::cout << std::endl << "+---------- Incorrect Box:" << std::endl;
    std::cout << "| ";
    std::string content;
    for (int i = 0; i < strlen(incorrectLetters); ++i) {
        content += incorrectLetters[i];
        content += " ";
    }
    int padding = 24 - content.length();
    std::cout << std::left << std::setw(23) << content << "|" << std::endl;
    std::cout << "+------------------------+" << std::endl;
    std::cout << incorrectLimit-incorrectCount << " more incorrect guesses." << std::endl;
}

void cleanup(std::string** hangmanText, int stages, std::string * words){
    for (int i = 0; i < stages; ++i) {
        delete[] hangmanText[i];
    }
    delete[] words;
    delete[] hangmanText;
}

void loadWords (int &totalLineCount, std::ifstream &inFile, std::string *&words) {
    std::string line;
    while (std::getline(inFile, line)) {
        totalLineCount++;
    }
    inFile.clear();
    inFile.seekg(0, std::ios::beg);
    words = new std::string[totalLineCount];
    for (int i = 0; i < totalLineCount; ++i) {
        std::getline(inFile, line);
        words[i] = line;
    }
}

void menu (int incorrectLimit, std::string **hangmanText, int lineCount) {
    std::cout << "Welcome to HANGMAN (1.1)!";
    for (int j = 0; j < lineCount; ++j) {
        std::cout << std::endl << hangmanText[incorrectLimit][j];
    }
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(100, '\n');
}