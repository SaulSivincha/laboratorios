#include <iostream>
#include <fstream>
#include <cstring>
#include "BinaryOperations.h"

using namespace std;

int main()
{
    int integerValue = 25;
    int readValue = 0;
    int numbers[10] = {1,2,3,4,5,6,7,8,9,0};
    double decimalValue = 18.75;
    char fileTitle[] = "Ejercicios ficheros binarios";

    BinaryData data;
    data.number = 100;
    strcpy(data.text, "Binary file data");

    ofstream inputWriter("entrada.dat", ios::binary);

    if (!inputWriter)
    {
        cout << "Input file could not be created" << endl;
        return 1;
    }

    inputWriter.write(reinterpret_cast<char*>(&integerValue), sizeof(integerValue));
    inputWriter.close();

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("entrada.dat", ios::binary);
    outputFile.open("salida.dat", ios::binary);

    if (!inputFile || !outputFile)
    {
        cout << "Files could not be opened" << endl;
        return 1;
    }

    writeInteger(outputFile, integerValue);
    writeDouble(outputFile, decimalValue);
    writeFirstFiveIntegers(outputFile, numbers);
    writeFirstTenCharacters(outputFile, fileTitle);
    writeBinaryData(outputFile, data);
    readInteger(inputFile, readValue);

    inputFile.close();
    outputFile.close();

    cout << "Read integer value: " << readValue << endl;
    cout << "Binary operations completed" << endl;

    return 0;
}