#include <iostream>
#include <string>
#include <cstring>

bool optionValidation(std::string userOption, char options[]){
    for (int i = 0; i < (strlen(options)); ++i) {
        if (tolower(userOption[0]) == options[i] && (size(userOption) == 1)) {
            return false;
        }
    }
    return true;
}

double calculations(std::string option, int amount) {
    int currentAmount = 1;
    double number;
    double finalNumber;

    for (int i = 0; i < amount; ++i) {
        std::cout << "\nInput number " << currentAmount << "\n>> ";
        std::cin >> number;
        while (!std::cin || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid Number! Please try again.\n>> ";
            std::cin >> number;
        }
        if (i != 1) {
            switch (tolower(option[0])) {
                case 'a':
                    finalNumber += number;
                    break;
                case 's':
                    finalNumber -= number;
                    break;
                case 'm':
                    finalNumber *= number;
                    break;
                case 'd':
                    finalNumber /= number;
                    break;
                default:
                    std::cout << "An error has occured. Please try again!" << std::endl;
                    return 0;
            }
        } else {
            finalNumber = number;
        }
        ++currentAmount;
    }
    std::cout << "\nYour number is: ";
    return finalNumber;
}

int main() {

    std::string userOption;
    char options[4] = {'a', 's', 'm', 'd'};
    char quitOptions[2] = {'y', 'n'};
    int numberAmout;

    std::cout << "Welcome to my calculator app! (1.0)\n" << std::endl;
    std::cout << "Addition (A)\nSubtraction (S)\nMultiplication (M)\nDivision (D)" << std::endl;
    std::cout << ">> ";

    std::cin >> userOption;
    while (optionValidation(userOption, options)) {
        std::cout << "Invalid Option! Please try again.\n>> ";
        std::cin >> userOption;
    }

    std::cout << "\nInput how many numbers\n>> ";
    std::cin >> numberAmout;
    while (!std::cin || std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid Number! Please try again.\n>> ";
        std::cin >> numberAmout;
    }

    std::cout << calculations(userOption, numberAmout) << std::endl;
    std::cout << "\nWould you like to use the program again? (Y/N)\n>> ";
    std::cin >> userOption;
    while (optionValidation(userOption, quitOptions)) {
        std::cout << "Invalid Option! Please try again.\n>> ";
        std::cin >> userOption;
    }
}
