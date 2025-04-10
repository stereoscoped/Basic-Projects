#include <iostream>
#include <fstream>
#include <string>

// Function Prototypes
void printList ();
void addList ();

int main() {
    std::ifstream inFile("list.txt");
    int size = 0;
    std::string line;
    if (!inFile) {
        std::cout << "Could not read list.txt" << std::endl;
        return 1;
    }
    while (std::getline(inFile, line)) {
        ++size;
    }

    inFile.clear();
    inFile.seekg(0, std::ios::beg);

    std::string list[size];
    int i = 0;
    while (std::getline(inFile, line)) {
        list[i] = line;
        ++i;
    }
    bool cont = true;
    std::ofstream outFile("list.txt");
    while (cont) {
        std::cout << "Welcome To my To Do List" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << "- " << list[i] << std::endl;
        }
        std::cout << "Add to the list\n>> ";
        std::getline(std::cin, line);
        if (line == "q" || line == "Q") {
            cont = false;
        }
        for (int k = 0; k < size; ++k) {
            outFile << list[k] << "\n";
        }
        outFile << line << "\n";
    }

    return 0;
}