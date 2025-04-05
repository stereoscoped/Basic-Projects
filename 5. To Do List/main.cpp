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
    std::cout << size << std::endl;
    std::cout << "Welcome To my To Do List" << std::endl;
    
    return 0;
}