#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, resultado;
    int opcion;

    cout << "===== CALCULADORA =====" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exponencial (cuadrado)" << endl;
    cout << "6. 1 entre un numero" << endl;
    cout << "7. Raiz cuadrada" << endl;
    cout << "8. Porcentaje" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch(opcion)
    {
        case 1:
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            resultado = a + b;
            break;

        case 2:
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            resultado = a - b;
            break;

        case 3:
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            resultado = a * b;
            break;

        case 4:
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            if (b != 0)
                resultado = a / b;
            else
            {
                cout << "Error: division por cero" << endl;
                return 0;
            }
            break;

        case 5:
            cout << "Ingrese un numero: ";
            cin >> a;
            resultado = pow(a, 2);
            break;

        case 6:
            cout << "Ingrese un numero: ";
            cin >> a;
            if (a != 0)
                resultado = 1 / a;
            else
            {
                cout << "Error: division por cero" << endl;
                return 0;
            }
            break;

        case 7:
            cout << "Ingrese un numero: ";
            cin >> a;
            if (a >= 0)
                resultado = sqrt(a);
            else
            {
                cout << "Error: raiz de numero negativo" << endl;
                return 0;
            }
            break;

        case 8:
            cout << "Ingrese el numero y el porcentaje: ";
            cin >> a >> b;
            resultado = (a * b) / 100;
            break;

        default:
            cout << "Opcion invalida" << endl;
            return 0;
    }

    cout << "Resultado: " << resultado << endl;

    return 0;
}
