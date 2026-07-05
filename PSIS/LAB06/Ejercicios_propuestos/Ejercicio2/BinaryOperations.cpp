#include "BinaryOperations.h"

void writeInteger(std::ofstream& outputFile, int value)
{
    outputFile.write(reinterpret_cast<char*>(&value), sizeof(value));
}

void writeDouble(std::ofstream& outputFile, double value)
{
    outputFile.write(reinterpret_cast<char*>(&value), sizeof(value));
}

void writeFirstFiveIntegers(std::ofstream& outputFile, int values[])
{
    outputFile.write(reinterpret_cast<char*>(values), 5 * sizeof(values[0]));
}

void writeFirstTenCharacters(std::ofstream& outputFile, char text[])
{
    outputFile.write(text, 10 * sizeof(char));
}

void writeBinaryData(std::ofstream& outputFile, BinaryData data)
{
    outputFile.write(reinterpret_cast<char*>(&data), sizeof(data));
}

void readInteger(std::ifstream& inputFile, int& value)
{
    inputFile.read(reinterpret_cast<char*>(&value), sizeof(value));
}