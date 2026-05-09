#include "Funciones.h"

int main() {
    Cliente arrClientes[25];
    cargarClientes(arrClientes);
    Pedido arrPedidos[150]{};
    cargarPedidos(arrPedidos);
    agregarPedidos(arrClientes,arrPedidos);
    eliminarPedidos(arrClientes);
    aplicarDescuentos(arrClientes);
    emitirReporte(arrClientes);

    return 0;
}
