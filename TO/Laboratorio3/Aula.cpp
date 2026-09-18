#include "Aula.h"

#include <iostream>
#include <stdexcept>
#include <utility>

Aula::Aula(std::string codigo, int capacidad)
    : codigo(std::move(codigo)), capacidad(capacidad)
{
    if (capacidad <= 0)
    {
        throw std::invalid_argument("La capacidad del aula debe ser positiva.");
    }
    std::cout << "Aula " << this->codigo << " creada." << '\n';
}

Aula::Aula(Aula &&otro) noexcept
    : codigo(std::move(otro.codigo)), capacidad(otro.capacidad)
{
}

Aula &Aula::operator=(Aula &&otro) noexcept
{
    if (this != &otro)
    {
        codigo = std::move(otro.codigo);
        capacidad = otro.capacidad;
    }
    return *this;
}

Aula::~Aula()
{
    if (!codigo.empty())
    {
        std::cout << "Aula " << codigo << " liberada." << '\n';
    }
}

Curso::Curso(std::string nombre, Aula &&aula)
    : nombre(std::move(nombre)), aula(std::move(aula)), docenteAsignado(nullptr)
{
}

void Curso::asignarDocente(Docente *docente)
{
    docenteAsignado = docente;
}
