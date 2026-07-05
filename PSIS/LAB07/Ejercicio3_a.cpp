#include <iostream>
#include <new>
using namespace std;

class MapBlock {
private:
    double heightData[500000];

public:
    MapBlock() {
        heightData[0] = 0.0;
    }
};

int main() {
    try {
        long long totalBlocks = 5000000;
        long double memoryPerBlock = sizeof(MapBlock);
        long double totalMemoryBytes = memoryPerBlock * totalBlocks;
        long double totalMemoryGB = totalMemoryBytes / (1024.0L * 1024.0L * 1024.0L);

        cout << "Iniciando construccion del mapa digital" << endl;
        cout << "Cantidad de bloques solicitados: " << totalBlocks << endl;
        cout << "Memoria aproximada por bloque: " << memoryPerBlock << " bytes" << endl;
        cout << "Memoria total aproximada requerida: " << totalMemoryGB << " GB" << endl;
        cout << "Intentando reservar memoria con new..." << endl;

        MapBlock* worldMap = new MapBlock[totalBlocks];

        cout << "Mapa digital creado correctamente" << endl;

        delete[] worldMap;
    } catch (const bad_alloc& error) {
        cout << "No se pudo completar la reserva de memoria" << endl;
        cout << "El sistema no tiene memoria suficiente para crear todos los bloques del mapa" << endl;
        cout << "Excepcion capturada: " << error.what() << endl;
    }

    return 0;
}