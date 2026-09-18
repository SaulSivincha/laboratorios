#ifndef AULA_H
#define AULA_H

#include <string>

class Docente;

class Aula
{
private:
    std::string codigo;
    int capacidad;

public:
    Aula(std::string codigo, int capacidad);
    Aula(const Aula &) = delete;
    Aula &operator=(const Aula &) = delete;
    Aula(Aula &&otro) noexcept;
    Aula &operator=(Aula &&otro) noexcept;
    ~Aula();
};

class Curso
{
private:
    std::string nombre;
    Aula aula;
    Docente *docenteAsignado;

public:
    Curso(std::string nombre, Aula &&aula);
    void asignarDocente(Docente *docente);
};

#endif
