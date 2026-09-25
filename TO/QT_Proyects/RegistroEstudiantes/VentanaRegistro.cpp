#include "VentanaRegistro.h"
#include "Estudiante.h"

#include <QFormLayout>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

VentanaRegistro::VentanaRegistro(QWidget *parent) : QWidget(parent) {
    setMinimumSize(620, 620);
    setStyleSheet(R"(
        QWidget { background: #f4f0e6; color: #111111; font-family: "DejaVu Sans Mono"; font-size: 14px; font-weight: 600; }
        QFrame#masthead { background: #ff4d00; border: 4px solid #111111; }
        QFrame#card { background: #ffffff; border: 4px solid #111111; }
        QLabel#title { background: #111111; color: #f4f0e6; font-size: 26px; font-weight: 900; letter-spacing: 1px; padding: 10px 12px; }
        QLabel#subtitle { color: #111111; font-size: 12px; font-weight: 800; padding: 3px 12px 10px 12px; }
        QLabel#section { background: #dfff00; color: #111111; border: 3px solid #111111; font-size: 14px; font-weight: 900; padding: 7px 9px; }
        QLineEdit { background: #ffffff; border: 3px solid #111111; border-radius: 0; color: #111111; padding: 10px; selection-background-color: #dfff00; }
        QLineEdit:focus { background: #dfff00; border: 3px solid #111111; }
        QPushButton { border: 3px solid #111111; border-radius: 0; font-weight: 900; padding: 11px 16px; }
        QPushButton#register { background: #ff4d00; color: #111111; }
        QPushButton#register:hover { background: #dfff00; }
        QPushButton#register:pressed { background: #111111; color: #ffffff; }
        QPushButton#clear { background: #ffffff; color: #111111; }
        QPushButton#clear:hover { background: #111111; color: #ffffff; }
        QListWidget { background: #ffffff; border: 4px solid #111111; border-radius: 0; padding: 3px; }
        QListWidget::item { border-bottom: 2px solid #111111; padding: 10px; }
        QListWidget::item:selected { background: #ff4d00; color: #111111; }
    )");

    auto *layoutPrincipal = new QVBoxLayout(this);
    layoutPrincipal->setContentsMargins(22, 22, 22, 22);
    layoutPrincipal->setSpacing(12);

    auto *cabecera = new QFrame;
    cabecera->setObjectName("masthead");
    auto *layoutCabecera = new QVBoxLayout(cabecera);
    layoutCabecera->setContentsMargins(10, 10, 10, 10);
    layoutCabecera->setSpacing(0);
    auto *titulo = new QLabel("REGISTRO / ESTUDIANTES");
    titulo->setObjectName("title");
    auto *subtitulo = new QLabel("SISTEMA DE ALTAS  —  SESIÓN ACTIVA");
    subtitulo->setObjectName("subtitle");
    layoutCabecera->addWidget(titulo);
    layoutCabecera->addWidget(subtitulo);
    layoutPrincipal->addWidget(cabecera);

    auto *tarjeta = new QFrame;
    tarjeta->setObjectName("card");
    auto *contenido = new QVBoxLayout(tarjeta);
    contenido->setContentsMargins(24, 22, 24, 22);
    contenido->setSpacing(14);

    auto *datos = new QLabel("01 // DATOS DEL ESTUDIANTE");
    datos->setObjectName("section");
    contenido->addWidget(datos);

    edtNombre = new QLineEdit;
    edtNombre->setPlaceholderText("Ej.: Ana Quispe");
    edtCodigo = new QLineEdit;
    edtCodigo->setPlaceholderText("Ej.: 20231234");
    edtCodigo->setClearButtonEnabled(true);

    auto *formulario = new QFormLayout;
    formulario->setHorizontalSpacing(18);
    formulario->setVerticalSpacing(12);
    formulario->addRow("NOMBRE COMPLETO:", edtNombre);
    formulario->addRow("CÓDIGO:", edtCodigo);
    contenido->addLayout(formulario);

    auto *botones = new QHBoxLayout;
    btnLimpiar = new QPushButton("LIMPIAR");
    btnLimpiar->setObjectName("clear");
    btnRegistrar = new QPushButton("+ REGISTRAR");
    btnRegistrar->setObjectName("register");
    btnRegistrar->setDefault(true);
    botones->addWidget(btnLimpiar);
    botones->addStretch();
    botones->addWidget(btnRegistrar);
    contenido->addLayout(botones);

    lblResultado = new QLabel("ESTADO: SIN REGISTROS. ESPERANDO DATOS.");
    lblResultado->setWordWrap(true);
    contenido->addWidget(lblResultado);

    layoutPrincipal->addWidget(tarjeta);

    auto *historial = new QLabel("02 // HISTORIAL DE SESIÓN");
    historial->setObjectName("section");
    layoutPrincipal->addWidget(historial);
    lstEstudiantes = new QListWidget;
    lstEstudiantes->setMinimumHeight(145);
    lstEstudiantes->setAlternatingRowColors(true);
    layoutPrincipal->addWidget(lstEstudiantes, 1);

    connect(btnRegistrar, &QPushButton::clicked, this, &VentanaRegistro::registrarEstudiante);
    connect(btnLimpiar, &QPushButton::clicked, this, &VentanaRegistro::limpiarFormulario);
    connect(edtCodigo, &QLineEdit::returnPressed, this, &VentanaRegistro::registrarEstudiante);
}

void VentanaRegistro::registrarEstudiante() {
    const QString nombre = edtNombre->text().trimmed();
    const QString codigo = edtCodigo->text().trimmed();

    if (nombre.isEmpty() || codigo.isEmpty()) {
        mostrarMensaje("Completa ambos campos antes de registrar.", true);
        return;
    }

    Estudiante estudiante(nombre.toStdString(), codigo.toStdString());
    lstEstudiantes->addItem(QString("%1  ·  %2").arg(nombre, codigo));
    mostrarMensaje(QString("✓ Estudiante registrado: %1 (%2)").arg(nombre, codigo));
    edtNombre->clear();
    edtCodigo->clear();
    edtNombre->setFocus();
}

void VentanaRegistro::limpiarFormulario() {
    edtNombre->clear();
    edtCodigo->clear();
    mostrarMensaje("Formulario reiniciado. Puedes registrar un nuevo estudiante.");
    edtNombre->setFocus();
}

void VentanaRegistro::mostrarMensaje(const QString &mensaje, bool esError) {
    lblResultado->setText(mensaje);
    lblResultado->setStyleSheet(esError
        ? "color: #b91c1c; font-weight: 600;"
        : "color: #047857; font-weight: 600;");
}
