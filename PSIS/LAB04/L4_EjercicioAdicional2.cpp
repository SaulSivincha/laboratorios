#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    Persona* siguiente;
};

void agregarPersona(Persona*& frente, Persona*& final, string nombre) {
    Persona* nueva = new Persona;
    nueva->nombre = nombre;
    nueva->siguiente = nullptr;

    if (frente == nullptr) {
        frente = nueva;
        final = nueva;
    } else {
        final->siguiente = nueva;
        final = nueva;
    }

    cout << "Persona agregada a la cola: " << nombre << endl;
}

void atenderPersona(Persona*& frente, Persona*& final) {
    if (frente == nullptr) {
        cout << "No hay personas en la cola." << endl;
        return;
    }

    Persona* temporal = frente;
    cout << "Atendiendo a: " << frente->nombre << endl;

    frente = frente->siguiente;

    if (frente == nullptr) {
        final = nullptr;
    }

    delete temporal;
}

void mostrarFrente(Persona* frente) {
    if (frente == nullptr) {
        cout << "La cola esta vacia." << endl;
    } else {
        cout << "Primera persona en la cola: " << frente->nombre << endl;
    }
}

void mostrarCola(Persona* frente) {
    if (frente == nullptr) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    cout << "\nPersonas en la cola:\n";

    Persona* actual = frente;

    while (actual != nullptr) {
        cout << "- " << actual->nombre << endl;
        actual = actual->siguiente;
    }
}

void liberarCola(Persona*& frente, Persona*& final) {
    while (frente != nullptr) {
        Persona* temporal = frente;
        frente = frente->siguiente;
        delete temporal;
    }

    final = nullptr;
}

int main() {
    Persona* frente = nullptr;
    Persona* final = nullptr;

    agregarPersona(frente, final, "Sebastian");
    agregarPersona(frente, final, "Rodrigo");
    agregarPersona(frente, final, "Diego");

    mostrarCola(frente);

    mostrarFrente(frente);

    atenderPersona(frente, final);
    mostrarFrente(frente);

    atenderPersona(frente, final);
    mostrarFrente(frente);

    liberarCola(frente, final);

    return 0;
}
