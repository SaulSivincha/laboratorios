        #include <iostream>
using namespace std;

class Tanque {
private:
    double contenido;

public:
    static const int capacidad = 5000;

    Tanque();

    double getContenido() const;

    void agregar(double cantidad);

    void sacar(double cantidad);

    void sacaMitad();
};

Tanque::Tanque() {
    contenido = 0;
}

double Tanque::getContenido() const {
    return contenido;
}

void Tanque::agregar(double cantidad) {
    if (cantidad > 0) {
        contenido = contenido + cantidad;
        
        if (contenido > capacidad) {
            contenido = capacidad;
        }
    }
}

void Tanque::sacar(double cantidad) {
    if (cantidad > 0) {
        contenido = contenido - cantidad;

        if (contenido < 0) {
            contenido = 0;
        }
    }
}

void Tanque::sacaMitad() {
    if (contenido > 0) {
        contenido = contenido / 2;
    }
}

int main() {
    Tanque t;

    t.agregar(100);

    cout << "Contenido inicial: " << t.getContenido() << endl;

    while (t.getContenido() >= 1.0) {
        t.sacaMitad();
        cout << "Contenido actual: " << t.getContenido() << endl;
    }

    cout << "Contenido final: " << t.getContenido() << endl;

    return 0;
}