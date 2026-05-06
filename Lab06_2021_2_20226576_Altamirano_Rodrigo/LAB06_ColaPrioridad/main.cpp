#include <cstdlib>
#include "BibGenerica.h"
#include "BibImpresion.h"
#include "FunConEnteros.h"
#include "FunConRegistros.h"

using namespace std;

int main() {
    void* cola;
    creacola(cola,leenumero,prioridadnumero,"numeros.txt");
    descargarcola(cola,muestranumero,"Orden.txt");

    creacola(cola,leepedido,prioridadpedido,"Pedidos.csv");
    descargarcola(cola,muestrapedido,"Ordenpedidos.txt");

    return 0;
}
