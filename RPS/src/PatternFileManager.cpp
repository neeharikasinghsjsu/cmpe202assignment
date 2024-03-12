#include<fstream>
#include<iostream>
#include<map>
#include "PatternFileManager.h"


void PatternFileManager::savePatternsToFile(const std::map<std::string, int>& patterns, const std::string& fileName) {
    std::ofstream patternFrequencyFile(fileName);

    if(!patternFrequencyFile) {
        std::cerr << "Error opening file for writing: " << fileName << std::endl;
        return;
    }

    for (const auto& pair : patterns) {
        patternFrequencyFile << pair.first << " " << pair.second << "\n";
    }
    patternFrequencyFile.close();
}

std::map<std::string, int> PatternFileManager::loadPatternsFromFile(const std::string& fileName) {
    std::map<std::string, int> patterns;
    std::ifstream inFile(fileName);

    if (!inFile) {
        std::cerr << "Error opening file for reading: " << fileName << std::endl;
        return patterns;
    }

    std::string pattern;
    int frequency;
    while (inFile >> pattern >> frequency) {
        // This loop reads a string and an integer from each line of the file.
        patterns[pattern] = frequency;
    }
    
    inFile.close();
    return patterns;
}