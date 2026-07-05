#include <iostream>
#include <stdexcept>
using namespace std;

double divideNumbers(double dividend, double divisor) {
    try {
        if (divisor == 0) {
            throw runtime_error("Error: no se puede dividir entre cero");
        }

        return dividend / divisor;
    } catch (const runtime_error& error) {
        cout << "Excepcion tratada en la funcion divideNumbers" << endl;
        throw;
    }
}

int main() {
    double firstNumber;
    double secondNumber;

    cout << "Ingrese el primer numero: ";
    cin >> firstNumber;

    cout << "Ingrese el segundo numero: ";
    cin >> secondNumber;

    try {
        double result = divideNumbers(firstNumber, secondNumber);
        cout << "Resultado: " << result << endl;
    } catch (const runtime_error& error) {
        cout << "Excepcion tratada en el main" << endl;
        cout << error.what() << endl;
    }

    return 0;
}