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

void modificarPorValor(Curso curso) {
    curso.setCapacidad(50);

    std::cout << "Dentro de funcion por valor: "
              << curso.getCapacidad() << std::endl;
}

void modificarPorReferencia(Curso &curso) {
    curso.setCapacidad(60);

    std::cout << "Dentro de funcion por referencia: "
              << curso.getCapacidad() << std::endl;
}

int main() {
    Curso curso("Tecnologia de Objetos", 30);

    std::cout << "\nCapacidad original: "
              << curso.getCapacidad() << std::endl;

    std::cout << "\n Paso por valor " << std::endl;

    std::cout << "Antes: "
              << curso.getCapacidad() << std::endl;

    modificarPorValor(curso);

    std::cout << "Despues: "
              << curso.getCapacidad() << std::endl;

    std::cout << "\nPaso por referencia " << std::endl;

    std::cout << "Antes: "
              << curso.getCapacidad() << std::endl;

    modificarPorReferencia(curso);

    std::cout << "Despues: "
              << curso.getCapacidad() << std::endl;

    return 0;
}