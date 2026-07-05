#include <iostream>
using namespace std;

const int MAX = 100;

void leerMatriz(double matriz[MAX][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Ingrese elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarMatriz(double matriz[MAX][MAX], int filas, int columnas) {
    cout << "\nMatriz ingresada:\n";

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

bool esMenorDeFila(double matriz[MAX][MAX], int fila, int columna, int columnas) {
    double valor = matriz[fila][columna];

    for (int j = 0; j < columnas; j++) {
        if (matriz[fila][j] < valor) {
            return false;
        }
    }

    return true;
}

bool esMayorDeColumna(double matriz[MAX][MAX], int fila, int columna, int filas) {
    double valor = matriz[fila][columna];

    for (int i = 0; i < filas; i++) {
        if (matriz[i][columna] > valor) {
            return false;
        }
    }

    return true;
}

bool buscarPuntoSilla(double matriz[MAX][MAX], int filas, int columnas) {
    bool encontrado = false;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (esMenorDeFila(matriz, i, j, columnas) &&
                esMayorDeColumna(matriz, i, j, filas)) {
                cout << "\nExiste punto de silla.";
                cout << "\nValor: " << matriz[i][j];
                cout << "\nPosicion: fila " << i << ", columna " << j << endl;

                encontrado = true;
            }
        }
    }

    return encontrado;
}

int main() {
    double matriz[MAX][MAX];
    int filas, columnas;

    cout << "Ingrese cantidad de filas: ";
    cin >> filas;

    cout << "Ingrese cantidad de columnas: ";
    cin >> columnas;

    leerMatriz(matriz, filas, columnas);
    mostrarMatriz(matriz, filas, columnas);

    bool existe = buscarPuntoSilla(matriz, filas, columnas);

    if (!existe) {
        cout << "\nNo existe punto de silla en la matriz." << endl;
    }

    return 0;
}
