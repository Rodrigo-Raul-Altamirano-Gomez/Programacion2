#include "Almacen.h"

using namespace std;

int main() {
    Almacen almacen;

    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();

    return 0;
}
