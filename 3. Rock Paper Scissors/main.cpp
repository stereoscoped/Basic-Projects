#include <random>
#include <iostream>

// Function Prototype
bool choiceValidation (char list[], char choice, int listSize);

int main() {
    char choice;
    char choiceList[8] = {'r', '1', 'p', '2', 's', '3', 'e', '4'};
    std::cout << "Rock Paper Scissors (1.0)!" << std::endl;

    while (choice != '4' && tolower(choice) != 'e') {
        std::cout << "\nRock (R or 1), Paper (P or 2), Scissors (S or 3), or Exit (E or 4)" << std::endl;
        std::cout << ">> ";
        std::cin >> choice;

        // Input validation
        while(!std::cin || std::cin.peek() != '\n' || choiceValidation(choiceList, choice, sizeof(choiceList))) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid Option! Please try again.\n>> ";
            std::cin >> choice;
        }

        if (choice != 'e' && choice != '4') {
            std::cout << "\nThe computer chose ";
            int computerChoice = rand()%3;
            int winLose = 2; // loose is 0, win is 1, tie is 2
            if (computerChoice == 0) {
                std::cout << "rock.";
                if (tolower(choice) == 'p' || tolower(choice) == '2') winLose = 1;
                else if (tolower(choice) == 's' || tolower(choice) == '3') winLose = 0;
            } else if (computerChoice == 1) {
                std::cout << "paper.";
                if (tolower(choice) == 's' || tolower(choice) == '3') winLose = 1;
                else if (tolower(choice) == 'r' || tolower(choice) == '1') winLose = 0;
            } else if (computerChoice == 2) {
                std::cout << "scissors.";
                if (tolower(choice) == 'r' || tolower(choice) == '1') winLose = 1;
                else if (tolower(choice) == 'p' || tolower(choice) == '2') winLose = 0;
            }
            if (winLose == 0) {
                std::cout << " You lost!" << std::endl;
            } else if (winLose == 1) {
                std::cout << " You Won!" << std::endl;
            } else std::cout << " You tied!" << std::endl;
        } else {
            std::cout << "\nGoodbye!" << std::endl;
        }
    }
}

// Function implementation
bool choiceValidation (char list[], char choice, int listSize) {
    for (int i = 0; i < listSize; ++i) {
        if (tolower(choice) == list[i]) {
            return false;
        }
    }
    return true;
}