#include "functions.h"

// Checks if inputted option is in the list of options
bool optionValidation(std::string userOption, char options[], int arraySize){
    for (int i = 0; i < arraySize; ++i) {
        if (tolower(userOption[0]) == options[i] && (size(userOption) == 1)) {
            return false;
        }
    }
    return true;
}

// This function collects numbers and calculates them based on user input
double collectCalculate(std::string option, int amount) {
    double number;
    double numberList[amount];
    double finalNumber;

    // Gets numbers
    for (int i = 0; i < amount; ++i) {
        std::cout << "\nInput number " << (i + 1) << "\n>> ";
        std::cin >> number;
        while (!std::cin || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid Number! Please try again.\n>> ";
            std::cin >> number;
        }
        numberList[i] = number;
    }

    /* First number is excluded from the loop for functions that
    do not have the commutative property (first number is important) */
    std::cout << "\nWork shown:" << std::endl;
    std::cout << numberList[0];
    finalNumber = numberList[0];
    for (int j = 1; j < amount; ++j) {
        if (option[0] == 'a') {
            std::cout << " + " << numberList[j];
            finalNumber += numberList[j];
        } else if (option[0] == 's') {
            std::cout << " - " << numberList[j];
            finalNumber -= numberList[j];
        } else if (option[0] == 'm') {
            std::cout << " * " << numberList[j];
            finalNumber *= numberList[j];
        } else if (option[0] == 'd') {
            std::cout << " / " << numberList[j];
            finalNumber /= numberList[j];
        }
    }
    std::cout << " = " << finalNumber << std::endl;

    std::cout << "\nYour number is: ";
    return finalNumber;
}