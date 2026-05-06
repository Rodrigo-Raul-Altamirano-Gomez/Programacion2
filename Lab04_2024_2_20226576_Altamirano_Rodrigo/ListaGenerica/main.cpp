#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"
#include "ListaconRegistros.h"

using namespace std;

int main() {
    void* lista;

    crealista(lista,leenumeros,"numeros1.txt");
    cargalista(lista,compruebanumero,leeregnumeros,"numeros2.txt");
    muestralista(lista,imprimenumeros,"repnum.txt");

    crealista(lista,leeregistros,"Repartidores.csv");
    cargalista(lista,compruebaregistro,leeordenes,"Ordenes.csv");
    muestralista(lista,imprimeregistros,"repregistros.txt");

    return 0;
}
