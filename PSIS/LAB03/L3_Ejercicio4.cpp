#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lanzarDado() {
    return rand() % 6 + 1;
}

int lanzarDados() {
    int dado1 = lanzarDado();
    int dado2 = lanzarDado();
    int suma = dado1 + dado2;

    cout << "Dado 1: " << dado1 << " | Dado 2: " << dado2
         << " | Suma: " << suma << endl;

    return suma;
}

int main() {
    srand(time(0));

    int suma = lanzarDados();

    if (suma == 7 || suma == 11) {
        cout << "Ganaste en la primera tirada!" << endl;
    }
    else if (suma == 2 || suma == 3 || suma == 12) {
        cout << "Perdiste (craps)." << endl;
    }
    else {
        int punto = suma;
        cout << "Tu punto es: " << punto << endl;

        while (true) {
            suma = lanzarDados();

            if (suma == punto) {
                cout << "Volviste a obtener tu punto. Ganaste!" << endl;
                break;
            }
            else if (suma == 7) {
                cout << "Salio 7 antes del punto. Perdiste." << endl;
                break;
            }
        }
    }

    return 0;
}
