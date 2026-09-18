#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "Persona.h"

class Administrativo : public Persona
{
private:
    std::string area;

public:
    Administrativo(std::string nombre, std::string codigo, std::string area);
    void presentarse() const override;
};

#endif
