#include "Estudiante.h"

void porValor(Estudiante e) {
    std::cout << "[valor] direccion local: " << &e << std::endl;
}

void porReferencia(Estudiante &e) {
    std::cout << "[referencia] direccion: " << &e << std::endl;
}

void porPuntero(Estudiante *e) {
    std::cout << "[puntero] direccion: " << e << std::endl;
}

int main() {
    Estudiante e1("Ana Torres", "20261234");

    std::cout << "[original] direccion: " << &e1 << std::endl;

    porValor(e1);
    porReferencia(e1);
    porPuntero(&e1);

    Estudiante *e2 = new Estudiante("Luis Perez", "20265678");
    e2->mostrarDatos();
    delete e2;

    return 0;
}