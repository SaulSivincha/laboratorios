#include <iostream>

using namespace std;

int **createMatrix(int size) {
    int **matrix = new int *[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    return matrix;
}

void readMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> *(*(matrix + i) + j);
        }
    }
}

void printTranspose(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << *(*(matrix + j) + i) << "\t";
        }

        cout << endl;
    }
}

bool isSymmetric(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(*(matrix + i) + j) != *(*(matrix + j) + i)) {
                return false;
            }
        }
    }

    return true;
}

bool isAntisymmetric(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(*(matrix + i) + j) != -*(*(matrix + j) + i)) {
                return false;
            }
        }
    }

    return true;
}

bool isUpperTriangular(int **matrix, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (*(*(matrix + i) + j) != 0) {
                return false;
            }
        }
    }

    return true;
}

bool isLowerTriangular(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(*(matrix + i) + j) != 0) {
                return false;
            }
        }
    }

    return true;
}

void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void showMenu() {
    cout << endl;
    cout << "1. Transpose of A" << endl;
    cout << "2. Symmetric or antisymmetric" << endl;
    cout << "3. Upper or lower triangular" << endl;
    cout << "4. Exit" << endl;
    cout << "Option: ";
}

int main() {
    int size;
    int option;

    cout << "Size of the square matrix: ";
    cin >> size;

    if (size <= 0) {
        cout << "Matrix size must be positive." << endl;
        return 1;
    }

    int **matrix = createMatrix(size);

    cout << endl << "Enter values for matrix A:" << endl;
    readMatrix(matrix, size);

    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                cout << endl << "Transpose of A:" << endl;
                printTranspose(matrix, size);
                break;
            case 2:
                if (isSymmetric(matrix, size)) {
                    cout << "A is symmetric." << endl;
                } else {
                    cout << "A is not symmetric." << endl;
                }

                if (isAntisymmetric(matrix, size)) {
                    cout << "A is antisymmetric." << endl;
                } else {
                    cout << "A is not antisymmetric." << endl;
                }
                break;
            case 3:
                if (isUpperTriangular(matrix, size)) {
                    cout << "A is upper triangular." << endl;
                } else {
                    cout << "A is not upper triangular." << endl;
                }

                if (isLowerTriangular(matrix, size)) {
                    cout << "A is lower triangular." << endl;
                } else {
                    cout << "A is not lower triangular." << endl;
                }
                break;
            case 4:
                cout << "Program finished." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (option != 4);

    freeMatrix(matrix, size);

    return 0;
}
