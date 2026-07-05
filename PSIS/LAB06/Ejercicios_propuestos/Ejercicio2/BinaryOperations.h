#ifndef BINARY_OPERATIONS_H
#define BINARY_OPERATIONS_H

#include <fstream>

struct BinaryData
{
    int number;
    char text[100];
};

void writeInteger(std::ofstream& outputFile, int value);
void writeDouble(std::ofstream& outputFile, double value);
void writeFirstFiveIntegers(std::ofstream& outputFile, int values[]);
void writeFirstTenCharacters(std::ofstream& outputFile, char text[]);
void writeBinaryData(std::ofstream& outputFile, BinaryData data);
void readInteger(std::ifstream& inputFile, int& value);

#endif