#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <random>

int main() {
    std::string words[5] = {"hello","bye","snake","rat","apple"};
    char guess = ' ';
    int guessNumber = 1;
    int incorrectCount = 0;
    int incorrectLimit = 8;

    char word[50];
    strcpy(word, words[rand()%size(words)].c_str());
    while (incorrectCount < incorrectLimit) {
        bool incorrect = true;
        std::cout << "Guess " << guessNumber << ": ";
        std::cin >> guess;
        for (int i = 0; i < sizeof(word); ++i) {
            if (guess == word[i]) {
                std::cout << "Correct!" << std::endl;
                incorrect = false;
            }
        }
        if (incorrect) {
            std::cout << "Incorrect!" << std::endl;
            ++incorrectCount;
        }
        ++guessNumber;
    }

}