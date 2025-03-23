#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <iomanip>

void display(char *word, int *correctIndex, std::string **hangmanText, int incorrectCount, int lineCount, char *incorrectLetters, int incorrectLimit);
void cleanup(std::string** hangmanText, int stages, std::string * words);
void loadWords(int &totalLineCount, std::ifstream &inFile, std::string *&words);
void menu (int incorrectLimit, std::string **hangmanText, int lineCount);

#endif