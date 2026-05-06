#include "Bibliotecas/MainAuxiliares.h"

int main() {
    ifstream archClientes, archProductos, archPedidos;
    ofstream archReportePrueba;

    AbrirArchivos(archClientes, archProductos, archPedidos, archReportePrueba);

    ProbarSobrecargas(archClientes, archProductos, archPedidos, archReportePrueba);
}