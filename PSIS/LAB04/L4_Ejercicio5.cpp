#include <iostream>

using namespace std;

int **createMatrix(int rows, int columns) {
    int **matrix = new int *[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }

    return matrix;
}

void readMatrix(int **matrix, int rows, int columns, char name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << name << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> *(*(matrix + i) + j);
        }
    }
}

void multiplyMatrices(int **firstMatrix, int **secondMatrix, int **resultMatrix, int firstRows, int firstColumns, int secondColumns) {
    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < secondColumns; j++) {
            *(*(resultMatrix + i) + j) = 0;

            for (int k = 0; k < firstColumns; k++) {
                *(*(resultMatrix + i) + j) += *(*(firstMatrix + i) + k) * *(*(secondMatrix + k) + j);
            }
        }
    }
}

void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << *(*(matrix + i) + j) << "\t";
        }

        cout << endl;
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {
    int firstRows;
    int firstColumns;
    int secondRows;
    int secondColumns;

    cout << "Rows of the first matrix: ";
    cin >> firstRows;

    cout << "Columns of the first matrix: ";
    cin >> firstColumns;

    cout << "Rows of the second matrix: ";
    cin >> secondRows;

    cout << "Columns of the second matrix: ";
    cin >> secondColumns;

    if (firstRows <= 0 || firstColumns <= 0 || secondRows <= 0 || secondColumns <= 0) {
        cout << "Matrix dimensions must be positive." << endl;
        return 1;
    }

    if (firstColumns != secondRows) {
        cout << "The matrices cannot be multiplied." << endl;
        return 1;
    }

    int **firstMatrix = createMatrix(firstRows, firstColumns);
    int **secondMatrix = createMatrix(secondRows, secondColumns);
    int **resultMatrix = createMatrix(firstRows, secondColumns);

    cout << endl << "Enter values for the first matrix:" << endl;
    readMatrix(firstMatrix, firstRows, firstColumns, 'A');

    cout << endl << "Enter values for the second matrix:" << endl;
    readMatrix(secondMatrix, secondRows, secondColumns, 'B');

    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, firstRows, firstColumns, secondColumns);

    cout << endl << "Result matrix:" << endl;
    printMatrix(resultMatrix, firstRows, secondColumns);

    freeMatrix(firstMatrix, firstRows);
    freeMatrix(secondMatrix, secondRows);
    freeMatrix(resultMatrix, firstRows);

    return 0;
}
