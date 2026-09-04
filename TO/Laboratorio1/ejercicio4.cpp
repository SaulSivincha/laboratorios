#include <iostream>
#include <string>

class Estudiante {
private:
    std::string nombre;
    std::string codigo;

public:
    Estudiante(std::string nombre, std::string codigo)
        : nombre(nombre), codigo(codigo) {}

    void mostrarDatos() const {
        std::cout << "Estudiante: " << nombre
                  << " (" << codigo << ")" << std::endl;
    }
};

int main() {
    Estudiante lista[3] = {
        Estudiante("Ana Torres", "20261234"),
        Estudiante("Luis Ramos", "20265678"),
        Estudiante("Carla Medina", "20269876")
    };

    for (int i = 0; i < 3; i++) {
        lista[i].mostrarDatos();
    }

    return 0;
}