#include "Estudiante.h"

#include <iostream>
#include <utility>

int Estudiante::contador = 0;

Estudiante::Estudiante(std::string nombre, std::string codigo)
    : nombre(std::move(nombre)), codigo(std::move(codigo)) {
    orden = ++contador;
    std::cout << "Estudiante creado #" << orden << ": "
              << this->nombre << " (" << this->codigo << ")" << std::endl;
}
