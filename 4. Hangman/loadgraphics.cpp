#include "loadgraphics.h"

void readHangmanSize(std::ifstream & hangmanFile, int & stages, int & lineCount) {
    stages = 0;
    int endbracket = 0;
    std::string line;
    lineCount = 0;
    int count = 0;
    while (std::getline(hangmanFile, line)) {
        if (line == "{") {
            ++stages;
            count = 0;
        }
        if (line == "}") {
            ++endbracket;
            count = 0;
        }
        if (count > lineCount) {
            lineCount = count;
        }
        ++count;
    }

    if (stages != endbracket) {
        std::cout << "Error reading file!" << std::endl;
        return;
    }
    hangmanFile.clear();
    hangmanFile.seekg(0, std::ios::beg);
}

void readHangman(std::ifstream & hangmanFile, int & stages, int lineCount, std::string **hangmanText){
    int stageIndex = -1;
    int lineIndex = 0;
    std::string line;
    while (std::getline(hangmanFile, line)) {
        if (line == "{") {
            ++stageIndex;
            lineIndex = 0;
        }
        if ((line != "{") && (line != "}")) {
            hangmanText[stageIndex][lineIndex] = line;
            ++lineIndex;
        }
    }
    hangmanFile.close();
}

void loadHangmanGraphics(std::ifstream &hangmanFile, int &stages, int &lineCount, std::string**& hangmanText) {
    stages = 0;
    lineCount = 0;
    readHangmanSize(hangmanFile, stages, lineCount);
    hangmanText = new std::string*[stages];
    for (int i = 0; i < stages; ++i) {
        hangmanText[i] = new std::string[lineCount];
    }
    readHangman(hangmanFile, stages, lineCount, hangmanText);
}