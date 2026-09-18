#include "Administrativo.h"

#include <iostream>
#include <utility>

Administrativo::Administrativo(std::string nombre, std::string codigo, std::string area)
    : Persona(std::move(nombre), std::move(codigo)), area(std::move(area))
{
}

void Administrativo::presentarse() const
{
    std::cout << "Soy personal administrativo " << nombre
              << " (" << codigo << "), área: " << area << '\n';
}
