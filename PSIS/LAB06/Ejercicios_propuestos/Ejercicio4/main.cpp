#include <iostream>
#include <string>
#include "FileViewer.h"

int main()
{
    std::string fileName;

    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);

    showFileWithPause(fileName);

    return 0;
}