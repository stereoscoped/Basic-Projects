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
    for (int j = 0; j < size; ++j) {
        std::cout << list[j] << std::endl;
    }
    std::cout << size << std::endl;
    std::cout << i << std::endl;
    std::cout << "Welcome To my To Do List" << std::endl;
    std::ofstream outFile("list.txt");
    std::getline(std::cin, line);
    outFile << line;
    return 0;
}