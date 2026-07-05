#include "PhraseFile.h"
#include <iostream>
#include <fstream>
#include <string>

void savePhrases(const std::string& fileName)
{
    std::ofstream outputFile(fileName);

    if (!outputFile)
    {
        std::cout << "File could not be created" << std::endl;
        return;
    }

    std::string phrase;

    std::cout << "Type phrases and press Enter without typing anything to finish" << std::endl;

    while (true)
    {
        std::cout << "Phrase: ";
        std::getline(std::cin, phrase);

        if (phrase.empty())
        {
            break;
        }

        outputFile << phrase << std::endl;
    }

    outputFile.close();
}

void showFileContent(const std::string& fileName)
{
    std::ifstream inputFile(fileName);

    if (!inputFile)
    {
        std::cout << "File could not be opened" << std::endl;
        return;
    }

    std::string line;

    std::cout << std::endl;
    std::cout << "Content of " << fileName << ":" << std::endl;

    while (std::getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }

    inputFile.close();
}