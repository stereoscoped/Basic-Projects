#include "functions.h"

int main() {
    std::cout << "Welcome to my calculator app! (1.0)" << std::endl;

    // userOption is used for any input that isnt a number
    std::string userOption = "y";
    while (userOption[0] == 'y') {

        // for data validation purposes, all options are in lists
        char options[4] = {'a', 's', 'm', 'd'};
        char quitOptions[2] = {'y', 'n'};
        int numberAmout;
        std::cout << "\nAddition (A)\nSubtraction (S)\nMultiplication (M)\nDivision (D)" << std::endl;
        std::cout << ">> ";

        // Prompts user to choose operator with data validation
        std::cin >> userOption;
        while (optionValidation(userOption, options, sizeof(options))) {
            std::cout << "Invalid Option! Please try again.\n>> ";
            std::cin >> userOption;
        }

        // To have multiple numbers be calculated rather than just 2
        std::cout << "\nInput how many numbers\n>> ";
        std::cin >> numberAmout;
        while (!std::cin || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid Number! Please try again.\n>> ";
            std::cin >> numberAmout;
        }

        // Runs calculations and asks to repeat program
        std::cout << collectCalculate(userOption, numberAmout) << std::endl;
        std::cout << "\nWould you like to use the program again? (Y/N)\n>> ";
        std::cin >> userOption;

        // Data validation
        while (optionValidation(userOption, quitOptions, sizeof(quitOptions))) {
            std::cout << "Invalid Option! Please try again.\n>> ";
            std::cin >> userOption;
        }
    }
}
