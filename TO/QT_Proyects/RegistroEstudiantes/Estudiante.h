#pragma once

#include <string>

class Estudiante {
public:
    Estudiante(std::string nombre, std::string codigo);

private:
    std::string nombre;
    std::string codigo;
    int orden;
    static int contador;
};
