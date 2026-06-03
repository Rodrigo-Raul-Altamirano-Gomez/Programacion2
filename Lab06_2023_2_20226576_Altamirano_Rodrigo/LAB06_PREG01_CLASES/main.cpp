#include "Cliente.h"
#include "Producto.h"
#include "Pedido.h"

int main() {
    Cliente cliente;
    Producto producto;
    Pedido pedido;
    ifstream archClientes("Clientes.csv",ios::in);
    ifstream archProductos("Productos.csv",ios::in);
    ifstream archPedidos("Pedidos.csv",ios::in);
    ofstream archReportePrueba("ReportePrueba.txt",ios::out);
    archClientes>>cliente;
    archProductos>>producto;
    archPedidos>>pedido;
    producto+=pedido;
    cliente+=pedido;
    archReportePrueba<<cliente;
    archReportePrueba<<producto;
    return 0;
}
