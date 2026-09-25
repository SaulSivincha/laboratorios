#include <QApplication>

#include "VentanaRegistro.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VentanaRegistro ventana;
    ventana.setWindowTitle("Registro de Estudiantes");
    ventana.show();

    return app.exec();
}
