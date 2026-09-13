#include "Estudiante.h"

Estudiante::Estudiante(std::string nombre, std::string codigo)
    : nombre(nombre), codigo(codigo) {
    std::cout << "Estudiante creado: " << nombre << std::endl;
}

Estudiante::~Estudiante() {
    std::cout << "Estudiante destruido: " << nombre << std::endl;
}

std::string Estudiante::getNombre() const {
    return nombre;
}

void Estudiante::setNombre(std::string n) {
    nombre = n;
}

void Estudiante::mostrarDatos() const {
    std::cout << "Estudiante: " << nombre
              << " (" << codigo << ")" << std::endl;
}