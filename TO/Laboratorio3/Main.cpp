#include "Aula.h"
#include "Administrativo.h"
#include "Docente.h"
#include "Evaluable.h"
#include "Estudiante.h"

#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::vector<std::unique_ptr<Persona>> personas;
    personas.push_back(std::make_unique<Estudiante>(
        "Ana Torres", "20261234", "Ingeniería de Sistemas"));
    personas.push_back(std::make_unique<Docente>(
        "Mg. Roxana Limache", "D-0456", "Ingeniería de Sistemas"));
    personas.push_back(std::make_unique<Administrativo>(
        "Carlos Medina", "A-102", "Recursos Humanos"));
    // Polimorfismo: cada objeto ejecuta SU version de presentarse()
    for (const auto &p : personas)
    {
        p->presentarse();

        if (const auto *evaluable = dynamic_cast<const Evaluable *>(p.get()))
        {
            std::cout << "Promedio simulado: " << evaluable->calcularNota() << '\n';
        }
    }
    // El Docente se crea de forma independiente y solo se
    // referencia desde el Curso; si el Curso se elimina, el Docente sigue existiendo.
    Docente profe("Mg. Roxana Limache", "D-0456", "Ingeniería de Sistemas");
    Curso curso("Tecnología de Objetos", Aula("A-201", 30));
    curso.asignarDocente(&profe);

    // Asociación: ambos existen por separado y el estudiante solo guarda
    // una referencia no propietaria al curso.
    Estudiante estudiante("Luis Ramos", "20264567", "Ingeniería de Sistemas");
    estudiante.matricular(&curso);
    std::cout << "Luis fue matriculado en el curso creado independientemente.\n";
    return 0;
}
