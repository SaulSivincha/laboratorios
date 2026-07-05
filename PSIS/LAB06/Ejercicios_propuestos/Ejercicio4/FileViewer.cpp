#include "FileViewer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

void showFileWithPause(const std::string& fileName) // Define la función que recibe el nombre del archivo
{
    std::ifstream inputFile(fileName); // Abre el archivo indicado en modo lectura

    if (!inputFile) // Verifica si el archivo no pudo abrirse
    {
        std::cout << "File could not be opened" << std::endl; // Muestra un mensaje de error
        return; // Termina la función si el archivo no se abrió
    }

    std::string line; // Variable donde se guardará cada línea leída del archivo
    int lineCounter = 0; // Contador para saber cuántas líneas se han mostrado

    while (std::getline(inputFile, line)) // Lee el archivo línea por línea hasta llegar al final
    {
        std::cout << line << std::endl; // Muestra en pantalla la línea leída
        lineCounter++; // Aumenta el contador de líneas mostradas

        if (lineCounter == 25) // Verifica si ya se mostraron 25 líneas
        {
            std::cout << std::endl; // Imprime una línea en blanco
            std::cout << "Press Enter to continue"; // Pide al usuario presionar Enter para continuar
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Espera a que el usuario presione Enter
            lineCounter = 0; // Reinicia el contador para contar otro bloque de 25 líneas
        }
    }

    inputFile.close(); // Cierra el archivo después de leerlo completamente
}