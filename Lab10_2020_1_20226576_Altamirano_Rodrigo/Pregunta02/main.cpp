#include "Bibliotecas/PlCola.h"
#include <iostream>
using namespace std;

int main() {
    PlCola<int> colaEnteros;
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    colaEnteros.encola(1);
    colaEnteros.encola(2);
    colaEnteros.encola(3);
    archReporte<<colaEnteros;
    colaEnteros.desencola();
    colaEnteros.desencola();
    archReporte<<colaEnteros;
    return 0;
}
