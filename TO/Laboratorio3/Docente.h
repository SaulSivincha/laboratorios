#ifndef DOCENTE_H
#define DOCENTE_H

#include "Persona.h"

class Docente : public Persona
{
private:
    std::string departamento;

public:
    Docente(std::string nombre, std::string codigo, std::string departamento);
    void presentarse() const override;
};

#endif
