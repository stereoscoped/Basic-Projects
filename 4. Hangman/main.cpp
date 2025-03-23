#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <iomanip>

void readHangmanSize(std::ifstream & hangmanFile, int & stages, int & lineCount) {
    stages = 0;
    int endbracket = 0;
    std::string line;
    lineCount = 0;
    int count = 0;
    while (std::getline(hangmanFile, line)) {
        if (line == "{") {
            ++stages;
            count = 0;
        }
        if (line == "}") {
            ++endbracket;
            count = 0;
        }
        if (count > lineCount) {
            lineCount = count;
        }
        ++count;
    }

    if (stages != endbracket) {
        std::cout << "Error reading file!" << std::endl;
        return;
    }
    hangmanFile.clear();
    hangmanFile.seekg(0, std::ios::beg);
}

void readHangman(std::ifstream & hangmanFile, int & stages, int lineCount, std::string **hangmanText){
    int stageIndex = -1;
    int lineIndex = 0;
    std::string line;
    while (std::getline(hangmanFile, line)) {
        if (line == "{") {
            ++stageIndex;
            lineIndex = 0;
        }
        if ((line != "{") && (line != "}")) {
            hangmanText[stageIndex][lineIndex] = line;
            ++lineIndex;
        }
    }
    hangmanFile.close();
}

void display(char *word, int *correctIndex, std::string **hangmanText, int incorrectCount, int lineCount, char *incorrectLetters, int incorrectLimit){
    for (int j = 0; j < strlen(word); ++j) {
        if (correctIndex[j] == 1) {
            std::cout << word[j];
        } else {
            std::cout << '_';
        }
    }
    std::cout << std::endl;

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

int main() {

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
    int stages = 0;
    int lineCount = 0;
    readHangmanSize(hangmanFile, stages, lineCount);
    std::string **hangmanText = new std::string*[stages];
    for (int i = 0; i < stages; ++i) {
        hangmanText[i] = new std::string[lineCount];
    }
    readHangman(hangmanFile, stages, lineCount, hangmanText);
    int incorrectLimit = stages - 1; 
    std::string line;
    int totalLineCount = 0;
    while (std::getline(inFile, line)) {
        totalLineCount++;
    }

    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    std::string words[totalLineCount];
    for (int i = 0; i < totalLineCount; ++i) {
        std::getline(inFile, line);
        words[i] = line;
        //std::cout << words[i] << std::endl;
    }

    char guess = ' ';
    int guessNumber = 1;
    int incorrectCount = 0;
    int correctCount = 0;
    char incorrectLetters[incorrectLimit] = {0};

    srand(time(0));
    int chosenWordIndex = rand()%totalLineCount;
    char * word = new char[words[chosenWordIndex].size()];
    strcpy(word, words[chosenWordIndex].c_str());

    int correctIndex[strlen(word)];
    for (int i = 0; i < strlen(word); ++i) {
        correctIndex[i] = 0;
    }

    display(word, correctIndex, hangmanText, incorrectCount, lineCount, incorrectLetters, incorrectLimit);
    while ((incorrectCount < incorrectLimit) && (correctCount < strlen(word))) {
        bool incorrect = true;
        std::cout << "\nGuess " << guessNumber << " >> ";
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
        display(word, correctIndex, hangmanText, incorrectCount, lineCount, incorrectLetters, incorrectLimit);
    }
    if (!(correctCount < strlen(word))) {
        std::cout << "You won!" << std::endl;
    } else {
        std::cout << "You lost! The word was " << word << std::endl;
    }
    delete[] word;
    for (int i = 0; i < stages; ++i) {
        delete[] hangmanText[i];
    }
    delete[] hangmanText;
    
    return 0;
}