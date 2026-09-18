#include "Estudiante.h"

#include <iostream>
#include <utility>

Estudiante::Estudiante(std::string nombre, std::string codigo, std::string carrera)
    : Persona(std::move(nombre), std::move(codigo)), carrera(std::move(carrera))
{
}

void Estudiante::presentarse() const
{
    std::cout << "Soy el estudiante " << nombre
              << " (" << codigo << "), carrera: " << carrera << '\n';
}

double Estudiante::calcularNota() const
{
    // Promedio simulado de las notas 16, 18 y 17.
    return (16.0 + 18.0 + 17.0) / 3.0;
}

void Estudiante::matricular(Curso *curso)
{
    if (curso != nullptr)
    {
        cursosMatriculados.push_back(curso);
    }
}
