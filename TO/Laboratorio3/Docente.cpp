#include "Docente.h"

#include <iostream>
#include <utility>

Docente::Docente(std::string nombre, std::string codigo, std::string departamento)
    : Persona(std::move(nombre), std::move(codigo)), departamento(std::move(departamento))
{
}

void Docente::presentarse() const
{
    std::cout << "Soy el docente " << nombre
              << " (" << codigo << "), departamento: " << departamento << '\n';
}
