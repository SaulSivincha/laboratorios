#include <iostream>
#include <string>

class Curso {
private:
    std::string nombre;
    int capacidad;

public:
    Curso(std::string nombre, int capacidad)
        : nombre(nombre), capacidad(capacidad) {
        std::cout << "Curso creado: " << nombre << std::endl;
    }

    ~Curso() {
        std::cout << "Curso destruido: " << nombre << std::endl;
    }

    std::string getNombre() const {
        return nombre;
    }

    void setNombre(std::string nuevoNombre) {
        nombre = nuevoNombre;
    }

    int getCapacidad() const {
        return capacidad;
    }

    void setCapacidad(int nuevaCapacidad) {
        capacidad = nuevaCapacidad;
    }
};

int main() {
    Curso curso("Tecnologia de Objetos", 30);

    std::cout << "Nombre: " << curso.getNombre() << std::endl;
    std::cout << "Capacidad: " << curso.getCapacidad() << std::endl;

    return 0;
}