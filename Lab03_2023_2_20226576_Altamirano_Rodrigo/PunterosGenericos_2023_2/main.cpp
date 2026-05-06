#include "Bibliotecas/PunterosGenericos.h"
#include "Bibliotecas/MuestraPunteros.h"

using namespace std;

int main() {
    void *productos,*clientes;

    cargaproductos(productos);
    cargaclientes(clientes);
    imprimeproductos(productos);
    imprimeclientes(clientes);
    cargapedidos(productos,clientes);
    imprimereporte(clientes);
    return 0;
}
