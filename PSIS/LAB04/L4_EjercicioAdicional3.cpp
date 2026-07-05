#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int NUM_NOTAS = 4;

struct Estudiante {
    char   nombre[30];
    int*   notas;
    double promedio;
};

void registrarEstudiantes(Estudiante* est, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "  Nombre: ";
        cin  >> est[i].nombre;

        est[i].notas = new int[NUM_NOTAS];

        for (int j = 0; j < NUM_NOTAS; j++) {
            cout << "  Nota " << j + 1 << ": ";
            cin  >> est[i].notas[j];
        }
    }
}

void calcularPromedios(Estudiante* est, int n) {
    for (int i = 0; i < n; i++) {
        double suma = 0;
        for (int j = 0; j < NUM_NOTAS; j++)
            suma += est[i].notas[j];
        est[i].promedio = suma / NUM_NOTAS;
    }
}

void ordenarPorPromedio(Estudiante* est, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (est[j].promedio < est[j + 1].promedio) {
                Estudiante temp = est[j];
                est[j]         = est[j + 1];
                est[j + 1]     = temp;
            }
        }
    }
}

void mostrarResultados(Estudiante* est, int n) {
    cout << "\n================================================\n";
    cout << "        RANKING DE ESTUDIANTES\n";
    cout << "================================================\n";
    cout << "Pos  Nombre              Notas          Promedio\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "   ";
        cout << est[i].nombre;
        for (int s = strlen(est[i].nombre); s < 20; s++) cout << " ";
        for (int j = 0; j < NUM_NOTAS; j++)
            cout << est[i].notas[j] << "  ";
        cout << "  " << est[i].promedio;
        cout << (est[i].promedio >= 11 ? "  APROBADO" : "  DESAPROBADO");
        cout << "\n";
    }
    cout << "================================================\n";
}

void mostrarEstadisticas(Estudiante* est, int n) {
    int aprobados    = 0;
    int desaprobados = 0;

    for (int i = 0; i < n; i++) {
        if (est[i].promedio >= 11) aprobados++;
        else desaprobados++;
    }

    cout << "\n-- Estadisticas --\n";
    cout << "Mayor promedio : " << est[0].nombre
         << " (" << est[0].promedio << ")\n";
    cout << "Menor promedio : " << est[n-1].nombre
         << " (" << est[n-1].promedio << ")\n";
    cout << "Aprobados      : " << aprobados   << "\n";
    cout << "Desaprobados   : " << desaprobados << "\n";
}

void liberarMemoria(Estudiante* est, int n) {
    for (int i = 0; i < n; i++)
        delete[] est[i].notas;
    delete[] est;
}

int main() {
    int n;
    cout << "Ingrese el numero de estudiantes: ";
    cin  >> n;

    Estudiante* estudiantes = new Estudiante[n];

    registrarEstudiantes(estudiantes, n);
    calcularPromedios(estudiantes, n);
    ordenarPorPromedio(estudiantes, n);
    mostrarResultados(estudiantes, n);
    mostrarEstadisticas(estudiantes, n);
    liberarMemoria(estudiantes, n);

    return 0;
}
