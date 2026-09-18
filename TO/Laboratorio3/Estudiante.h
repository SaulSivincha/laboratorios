#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"
#include "Evaluable.h"

class Curso;

#include <vector>

class Estudiante : public Persona, public Evaluable
{
private:
    std::string carrera;
    std::vector<Curso *> cursosMatriculados;

public:
    Estudiante(std::string nombre, std::string codigo, std::string carrera);
    void presentarse() const override;
    double calcularNota() const override;
    void matricular(Curso *curso);
};

#endif
