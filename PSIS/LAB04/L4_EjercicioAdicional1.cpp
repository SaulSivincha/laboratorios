#include <iostream>
#include <string>
using namespace std;

struct Pagina {
    string url;
    Pagina* anterior;
};

void visitarPagina(Pagina*& cima, string url) {
    Pagina* nueva = new Pagina;
    nueva->url = url;
    nueva->anterior = cima;
    cima = nueva;
}

void regresar(Pagina*& cima) {
    if (cima == nullptr) {
        cout << "No hay paginas en el historial." << endl;
        return;
    }

    Pagina* temporal = cima;
    cout << "Regresando desde: " << cima->url << endl;
    cima = cima->anterior;
    delete temporal;
}

void mostrarPaginaActual(Pagina* cima) {
    if (cima == nullptr) {
        cout << "No hay pagina actual." << endl;
    } else {
        cout << "Pagina actual: " << cima->url << endl;
    }
}

void liberarHistorial(Pagina*& cima) {
    while (cima != nullptr) {
        Pagina* temporal = cima;
        cima = cima->anterior;
        delete temporal;
    }
}

int main() {
    Pagina* historial = nullptr;

    visitarPagina(historial, "google.com");
    visitarPagina(historial, "unsa.edu.pe");
    visitarPagina(historial, "github.com");

    mostrarPaginaActual(historial);

    regresar(historial);
    mostrarPaginaActual(historial);

    regresar(historial);
    mostrarPaginaActual(historial);

    liberarHistorial(historial);

    return 0;
}
