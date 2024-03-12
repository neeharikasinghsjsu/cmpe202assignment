#ifndef PATTERNFILEMANAGER_H
#define PATTERNFILEMANAGER_H

#include<string>
#include<map>

class PatternFileManager {
public:
    static void savePatternsToFile(
        const std::map<std::string, int>& patterns, 
        const std::string& fileName); 
    static std::map<std::string, int> loadPatternsFromFile(const std::string& fileName);
};

#endif