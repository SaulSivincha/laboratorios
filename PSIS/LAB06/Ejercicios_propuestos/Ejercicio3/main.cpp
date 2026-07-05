#include "PhraseFile.h"

int main()
{
    const std::string fileName = "frases.txt";

    savePhrases(fileName);
    showFileContent(fileName);

    return 0;
}