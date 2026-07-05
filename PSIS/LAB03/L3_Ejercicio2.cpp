#include <iostream>
using namespace std;

int AreaCuadrilateros(double lado_a, double lado_b);
int AreaTriangulos(double lado_a, double altura_b);

int main(void)
{
    double a, b;
    int figura;

    cout << "Que figura quiere analizar, Cuadrado (1), Rectangulo (2), Triangulo (3): " << endl;
    cin >> figura;

    switch (figura)
    {
    case 1:
        cout << "introduzca el valor del lado" << endl;
        cin >> a;
        if (!AreaCuadrilateros(a, a))
            cout << "ojo el area es negativa " << endl;
        break;

    case 2:
        cout << "introduzca el valor del lado a y b:" << endl;
        cin >> a >> b;
        if (!AreaCuadrilateros(a, b))
            cout << "ojo el area es negativa " << endl;
        break;

    case 3:
        cout << "introduzca la base y la altura:" << endl;
        cin >> a >> b;
        if (!AreaTriangulos(a, b))
            cout << "ojo el area es negativa " << endl;
        break;

    default:
        cout << "figura equivocada" << endl;
        break;
    }

    return 0;
}

int AreaCuadrilateros(double lado_a, double lado_b)
{
    double area = lado_a * lado_b;
    cout << "El area es: " << area << endl;
    return (area >= 0);
}

int AreaTriangulos(double lado_a, double altura_b)
{
    double area = (lado_a * altura_b) / 2;
    cout << "El area es: " << area << endl;
    return (area >= 0);
}
