#include <iostream>
using namespace std;

double Suma(double x, double y);
double Producto(double x, double y);

int main()
{
    double a, b;
    int c;

    cout << "Escribe un numero: "; cin >> a;
    cout << "Escribe otro numero: "; cin >> b;
    cout << "Que operacion deseas hacer? 1 (suma), 2 (producto): "; cin >> c;

    if (c == 1)
        cout << "El resultado de la suma es: " << Suma(a, b) << endl;
    else
        cout << "El resultado del producto es: " << Producto(a, b) << endl;
    return 0;
}

double Suma(double x, double y)
{
    return x + y;
}

double Producto(double x, double y)
{
    return x * y;
}
