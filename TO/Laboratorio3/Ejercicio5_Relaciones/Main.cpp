#include <iostream>
#include <string>

using namespace std;

class Habitacion {
};

class Casa {
private:
    Habitacion habitacion; // Composición
};

class Empleado {
private:
    string nombre;

public:
    Empleado(string nombre) {
        this->nombre = nombre;
    }
};

class Empresa {
private:
    Empleado* empleado; // Agregación

public:
    Empresa(Empleado* empleado) {
        this->empleado = empleado;
    }
};

class Reserva {
};

class Cliente {
public:
    void realizarReserva(Reserva* reserva) { // Asociación
        cout << "Reserva realizada" << endl;
    }
};

int main() {
    Casa casa;

    Empleado empleado("Carlos");
    Empresa empresa(&empleado);

    Cliente cliente;
    Reserva reserva;
    cliente.realizarReserva(&reserva);

    return 0;
}
