#include <iostream>
using namespace std;

void mostrarFila(int* fila, int filaActual, int totalFilas) {
    for (int s = 0; s < (totalFilas - filaActual - 1); s++)
        cout << "  ";
    for (int j = 0; j <= filaActual; j++)
        cout << fila[j] << "   ";
    cout << endl;
}

void calcularSiguienteFila(int* fila, int filaActual) {
    for (int j = filaActual; j >= 1; j--) {
        fila[j] = fila[j] + fila[j - 1];
    }
}

int main() {
    int n;
    cout << "Ingrese el numero de filas: ";
    cin >> n;

    int* fila = new int[n]();
    fila[0] = 1;

    cout << "\nTriangulo de Pascal:\n\n";

    for (int i = 0; i < n; i++) {
        if (i > 0)
            calcularSiguienteFila(fila, i);
        mostrarFila(fila, i, n);
    }

    delete[] fila;
    return 0;
}
