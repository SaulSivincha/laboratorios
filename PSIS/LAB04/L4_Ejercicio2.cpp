#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

const int MAX_ERRORES   = 6;
const int MAX_PALABRAS  = 8;
const int MAX_LEN       = 20;
const int MAX_LETRAS    = 26;

void cargarPalabras(char palabras[][MAX_LEN], int &total) {
    strcpy(palabras[0], "puntero");
    strcpy(palabras[1], "arreglo");
    strcpy(palabras[2], "funcion");
    strcpy(palabras[3], "variable");
    strcpy(palabras[4], "compilador");
    strcpy(palabras[5], "bucle");
    strcpy(palabras[6], "estructura");
    strcpy(palabras[7], "recursion");
    total = MAX_PALABRAS;
}

void dibujarAhorcado(int errores) {
    cout << "\n  +---+\n";
    cout << "  |   |\n";
    cout << "  |   " << (errores >= 1 ? "O" : " ") << "\n";
    cout << "  |  "
         << (errores >= 3 ? "/" : " ")
         << (errores >= 2 ? "|" : " ")
         << (errores >= 4 ? "\\" : " ") << "\n";
    cout << "  |  "
         << (errores >= 5 ? "/" : " ")
         << " "
         << (errores >= 6 ? "\\" : " ") << "\n";
    cout << "  |\n";
    cout << "=========\n";
}

void inicializarDescubiertas(char* descubiertas, int len) {
    for (int i = 0; i < len; i++)
        descubiertas[i] = '_';
    descubiertas[len] = '\0';
}

bool letraYaUsada(char* usadas, int totalUsadas, char letra) {
    for (int i = 0; i < totalUsadas; i++)
        if (usadas[i] == letra) return true;
    return false;
}

bool buscarLetra(const char* palabra, char* descubiertas, int len, char letra) {
    bool encontrada = false;
    for (int i = 0; i < len; i++) {
        if (palabra[i] == letra) {
            descubiertas[i] = letra;
            encontrada = true;
        }
    }
    return encontrada;
}

bool verificarVictoria(char* descubiertas, int len) {
    for (int i = 0; i < len; i++)
        if (descubiertas[i] == '_') return false;
    return true;
}

void mostrarEstado(char* descubiertas, char* usadas,
                   int totalUsadas, int errores, int len) {
    cout << "\nPalabra:       ";
    for (int i = 0; i < len; i++)
        cout << descubiertas[i] << " ";

    cout << "\nLetras usadas: ";
    for (int i = 0; i < totalUsadas; i++)
        cout << usadas[i] << " ";

    cout << "\nErrores: " << errores << "/" << MAX_ERRORES << "\n";
}

void ordenarUsadas(char* usadas, int totalUsadas) {
    for (int i = 0; i < totalUsadas - 1; i++)
        for (int j = 0; j < totalUsadas - i - 1; j++)
            if (usadas[j] > usadas[j + 1]) {
                char temp  = usadas[j];
                usadas[j]  = usadas[j + 1];
                usadas[j + 1] = temp;
            }
}

void jugar(const char* palabra) {
    int len = strlen(palabra);

    char* descubiertas = new char[len + 1];
    char* usadas       = new char[MAX_LETRAS];
    int   totalUsadas  = 0;
    int   errores      = 0;

    inicializarDescubiertas(descubiertas, len);

    while (errores < MAX_ERRORES && !verificarVictoria(descubiertas, len)) {
        dibujarAhorcado(errores);
        mostrarEstado(descubiertas, usadas, totalUsadas, errores, len);

        char letra;
        cout << "Ingresa una letra: ";
        cin  >> letra;
        letra = tolower(letra);

        if (letra < 'a' || letra > 'z') {
            cout << ">> Solo se permiten letras.\n";
            continue;
        }

        if (letraYaUsada(usadas, totalUsadas, letra)) {
            cout << ">> Esa letra ya fue ingresada.\n";
            continue;
        }

        usadas[totalUsadas++] = letra;
        ordenarUsadas(usadas, totalUsadas);

        if (buscarLetra(palabra, descubiertas, len, letra))
            cout << ">> Letra correcta!\n";
        else {
            errores++;
            cout << ">> Letra incorrecta.\n";
        }
    }

    dibujarAhorcado(errores);
    mostrarEstado(descubiertas, usadas, totalUsadas, errores, len);

    if (verificarVictoria(descubiertas, len))
        cout << "\n*** GANASTE! La palabra era: " << palabra << " ***\n";
    else
        cout << "\n*** PERDISTE. La palabra era: " << palabra << " ***\n";

    delete[] descubiertas;
    delete[] usadas;
}

int main() {
    srand(time(0));

    char palabras[MAX_PALABRAS][MAX_LEN];
    int  totalPalabras = 0;
    cargarPalabras(palabras, totalPalabras);

    char opcion = 's';
    while (opcion == 's' || opcion == 'S') {
        int indice = rand() % totalPalabras;
        cout << "\n=============================\n";
        cout << "    JUEGO DEL AHORCADO\n";
        cout << "=============================\n";

        jugar(palabras[indice]);

        cout << "\nDeseas jugar de nuevo? (s/n): ";
        cin  >> opcion;
    }

    cout << "\nGracias por jugar!\n";
    return 0;
}
