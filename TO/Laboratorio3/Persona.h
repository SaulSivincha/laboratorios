#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
protected:
    std::string nombre;
    std::string codigo;

public:
    Persona(std::string nombre, std::string codigo)
        : nombre(nombre), codigo(codigo) {}
    virtual ~Persona() = default;
    // Funcion virtual pura: convierte a Persona en clase abstracta
    virtual void presentarse() const = 0;
};

#endif
