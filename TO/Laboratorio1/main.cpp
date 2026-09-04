#include <iostream>
#include <string>

class Estudiante {
private:
    std::string nombre;
    std::string codigo;
    int edad;

public:
    Estudiante(std::string nombre, std::string codigo, int edad)
        : nombre(nombre), codigo(codigo) {
        setEdad(edad);
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int nuevaEdad) {
        if (nuevaEdad > 0) {
            edad = nuevaEdad;
        } else {
            edad = 0;
        }
    }

    void mostrarDatos() const {
        std::cout << "Estudiante: " << nombre
                  << " (" << codigo << ")"
                  << ", Edad: " << getEdad() << std::endl;
    }
};

int main() {
    Estudiante e1("Ana Torres", "20261234", 20);
    Estudiante e2("Luis Ramos", "20265678", 22);

    e1.mostrarDatos();
    e2.mostrarDatos();

    return 0;
}