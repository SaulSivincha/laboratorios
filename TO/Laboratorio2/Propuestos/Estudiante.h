#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>

class Estudiante {
private:
    std::string nombre;
    std::string codigo;

public:
    Estudiante(std::string nombre, std::string codigo);
    ~Estudiante();

    std::string getNombre() const;
    void setNombre(std::string n);
    void mostrarDatos() const;
};

#endif