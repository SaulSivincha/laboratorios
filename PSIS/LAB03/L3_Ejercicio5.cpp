#include <iostream>
using namespace std;

void paresImpares() {
    int num;

    for (int i = 1; i <= 10; i++) {
        cout << "Ingrese numero " << i << ": ";
        cin >> num;

        if (num % 2 == 0)
            cout << num << " es PAR" << endl;
        else
            cout << num << " es IMPAR" << endl;
    }
}

bool esPerfecto(int n) {
    int suma = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            suma += i;
    }

    return suma == n;
}

void numerosPerfectos() {
    int contador = 0;
    int num = 2;

    while (contador < 100) {
        if (esPerfecto(num)) {
            cout << num << endl;
            contador++;
        }
        num++;
    }
}

int invertirNumero(int num) {
    int invertido = 0;

    while (num > 0) {
        int digito = num % 10;
        invertido = invertido * 10 + digito;
        num /= 10;
    }

    return invertido;
}

int main() {
    int opcion;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Determinar pares e impares" << endl;
        cout << "2. Mostrar primeros 100 numeros perfectos" << endl;
        cout << "3. Invertir numero de 4 digitos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                paresImpares();
                break;

            case 2:
                numerosPerfectos();
                break;

            case 3: {
                int num;
                cout << "Ingrese un numero de 4 digitos: ";
                cin >> num;

                if (num >= 1000 && num <= 9999) {
                    cout << "Numero invertido: "
                         << invertirNumero(num) << endl;
                } else {
                    cout << "Error: debe ser un numero de 4 digitos." << endl;
                }
                break;
            }

            case 4:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
