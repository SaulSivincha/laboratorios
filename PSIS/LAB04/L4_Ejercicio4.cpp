#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TORRES = 7;
const int PISOS = 20;
const int DEPARTAMENTOS = 6;

void llenarAleatorio(int habitantes[TORRES][PISOS][DEPARTAMENTOS]) {
    for (int t = 0; t < TORRES; t++) {
        for (int p = 0; p < PISOS; p++) {
            for (int d = 0; d < DEPARTAMENTOS; d++) {
                habitantes[t][p][d] = rand() % 7;
            }
        }
    }

    cout << "\nLos departamentos fueron llenados aleatoriamente entre 0 y 6 habitantes.\n";
}

void modificarDepartamento(int habitantes[TORRES][PISOS][DEPARTAMENTOS]) {
    int torre, piso, departamento, nuevaCantidad;

    cout << "\nIngrese torre [1 - 7]: ";
    cin >> torre;

    cout << "Ingrese piso [1 - 20]: ";
    cin >> piso;

    cout << "Ingrese departamento [1 - 6]: ";
    cin >> departamento;

    if (torre < 1 || torre > TORRES ||
        piso < 1 || piso > PISOS ||
        departamento < 1 || departamento > DEPARTAMENTOS) {
        cout << "\nError: torre, piso o departamento fuera de rango.\n";
        return;
    }

    cout << "Ingrese nueva cantidad de habitantes [0 - 6]: ";
    cin >> nuevaCantidad;

    if (nuevaCantidad < 0 || nuevaCantidad > 6) {
        cout << "\nError: la cantidad debe estar entre 0 y 6.\n";
        return;
    }

    habitantes[torre - 1][piso - 1][departamento - 1] = nuevaCantidad;

    cout << "\nDepartamento modificado correctamente.\n";
}

int calcularTotalHabitantes(int habitantes[TORRES][PISOS][DEPARTAMENTOS]) {
    int total = 0;

    for (int t = 0; t < TORRES; t++) {
        for (int p = 0; p < PISOS; p++) {
            for (int d = 0; d < DEPARTAMENTOS; d++) {
                total += habitantes[t][p][d];
            }
        }
    }

    return total;
}

void mostrarPromedioPorPisoDeCadaTorre(int habitantes[TORRES][PISOS][DEPARTAMENTOS]) {
    cout << "\nB) Promedio de habitantes por piso de cada torre\n";

    for (int t = 0; t < TORRES; t++) {
        cout << "\nTorre " << t + 1 << ":\n";

        for (int p = 0; p < PISOS; p++) {
            int sumaPiso = 0;

            for (int d = 0; d < DEPARTAMENTOS; d++) {
                sumaPiso += habitantes[t][p][d];
            }

            int promedioPiso = sumaPiso / DEPARTAMENTOS;

            cout << "Piso " << p + 1
                 << " -> Promedio: " << promedioPiso
                 << " habitantes por departamento\n";
        }
    }
}

void mostrarPromedioPorTorre(int habitantes[TORRES][PISOS][DEPARTAMENTOS]) {
    cout << "\nC) Promedio de habitantes por torre\n";

    for (int t = 0; t < TORRES; t++) {
        int sumaTorre = 0;

        for (int p = 0; p < PISOS; p++) {
            for (int d = 0; d < DEPARTAMENTOS; d++) {
                sumaTorre += habitantes[t][p][d];
            }
        }

        int promedioTorre = sumaTorre / (PISOS * DEPARTAMENTOS);

        cout << "Torre " << t + 1
             << " -> Promedio: " << promedioTorre
             << " habitantes por departamento\n";
    }
}

void mostrarResultados(int habitantes[TORRES][PISOS][DEPARTAMENTOS]) {
    int total = calcularTotalHabitantes(habitantes);

    cout << "\n=====================================\n";
    cout << "RESULTADOS DEL COMPLEJO HABITACIONAL\n";
    cout << "=====================================\n";

    cout << "\nA) Cantidad total de habitantes del complejo: "
         << total << endl;

    mostrarPromedioPorPisoDeCadaTorre(habitantes);
    mostrarPromedioPorTorre(habitantes);
}

void mostrarMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Llenar departamentos aleatoriamente\n";
    cout << "2. Modificar cantidad de habitantes de un departamento\n";
    cout << "3. Mostrar cantidades solicitadas\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    int habitantes[TORRES][PISOS][DEPARTAMENTOS] = {0};
    int opcion;

    srand(time(NULL));

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                llenarAleatorio(habitantes);
                break;
            case 2:
                modificarDepartamento(habitantes);
                break;
            case 3:
                mostrarResultados(habitantes);
                break;
            case 4:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}
