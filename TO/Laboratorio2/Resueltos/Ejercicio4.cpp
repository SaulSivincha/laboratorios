#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Estudiante {
private:
    std::string nombre;
    std::string codigo;

public:
    Estudiante(std::string nombre, std::string codigo)
        : nombre(nombre), codigo(codigo) {
        std::cout << "Estudiante creado: " << nombre << std::endl;
    }

    ~Estudiante() {
        std::cout << "Estudiante destruido: " << nombre << std::endl;
    }

    std::string getNombre() const {
        return nombre;
    }

    std::string getCodigo() const {
        return codigo;
    }

    void mostrarDatos() const {
        std::cout << "Estudiante: " << nombre
                  << " (" << codigo << ")" << std::endl;
    }
};

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

    int getCapacidad() const {
        return capacidad;
    }
};

int main() {
    Curso curso("Tecnologia de Objetos", 30);

    std::vector<std::unique_ptr<Estudiante>> estudiantes;

    estudiantes.push_back(
        std::make_unique<Estudiante>("Ana Torres", "20261234")
    );

    estudiantes.push_back(
        std::make_unique<Estudiante>("Luis Perez", "20265678")
    );

    estudiantes.push_back(
        std::make_unique<Estudiante>("Marco Diaz", "20269012")
    );

    std::cout << "\nEstudiantes matriculados en "
              << curso.getNombre() << ":" << std::endl;

    for (const auto& estudiante : estudiantes) {
        estudiante->mostrarDatos();
    }

    return 0;
}