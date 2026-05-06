#include "BibliotecaGenerica.h"
#include "BibliotecaConductores.h"
#include "BibliotecaInfracciones.h"

using namespace std;

int main() {
    void* lista;
    generaLista(lista);
    creaLista(lista,leeconductores,cmpconductores,buscalistaconductores,"Conductores.csv");
    cargaUnidades(lista,"Unidades.csv");
    creaLista(lista,leeinfracciones,cmpinfracciones,buscalistainfraccion,"Faltas.csv");
    imprimeLista(lista,imprimeconductores,"repconductores.txt");
    return 0;
}
