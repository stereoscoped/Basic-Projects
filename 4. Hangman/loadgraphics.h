#ifndef LOADGRAPHICS_H
#define LOADGRAPHICS_H
#include "functions.h"

void readHangmanSize(std::ifstream & hangmanFile, int & stages, int & lineCount);
void readHangman(std::ifstream & hangmanFile, int & stages, int lineCount, std::string **hangmanText);
void loadHangmanGraphics(std::ifstream &hangmanFile, int &stages, int &lineCount, std::string**& hangmanText);

#endif