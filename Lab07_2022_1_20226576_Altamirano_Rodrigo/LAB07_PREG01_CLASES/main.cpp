#include "Cliente.h"

int main() {
    ifstream archClientes("clientes2.csv",ios::in);
    ifstream archPedidos("pedidos2.csv",ios::in);
    ofstream archReportePrueba("repPrueba.txt",ios::out);
    Cliente cliente;
    Pedido pedido;
    archClientes>>cliente;
    archReportePrueba<<cliente;
    archPedidos>>pedido;
    cliente=pedido;
    archReportePrueba<<cliente;
    cliente/25;
    archReportePrueba<<cliente;
    cliente-=pedido;
    archReportePrueba<<cliente;
    return 0;
}
