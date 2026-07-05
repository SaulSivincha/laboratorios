#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    double reactorTemperature;

    try {
        cout << "Sistema de control de reactor experimental" << endl;
        cout << "Ingrese la temperatura actual del reactor: ";
        cin >> reactorTemperature;

        if (cin.fail()) {
            throw invalid_argument("La temperatura ingresada no es valida");
        }

        cout << "Temperatura registrada correctamente: " << reactorTemperature << " grados" << endl;
    } catch (const invalid_argument& error) {
        cout << "Error en la lectura de temperatura" << endl;
        cout << "El sistema esperaba un valor numerico, pero recibio un tipo de dato incorrecto" << endl;
        cout << "Excepcion capturada: " << error.what() << endl;
    }

    return 0;
}