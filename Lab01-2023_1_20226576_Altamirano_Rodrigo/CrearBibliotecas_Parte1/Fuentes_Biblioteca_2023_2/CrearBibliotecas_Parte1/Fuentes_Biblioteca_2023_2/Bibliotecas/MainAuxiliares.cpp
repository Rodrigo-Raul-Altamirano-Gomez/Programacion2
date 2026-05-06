//
// Created by hrodic on 3/04/2026.
//
#include "AperturaDeArchivos.h"
#include "MainAuxiliares.h"
#include "Estructuras.h"
#include "OperadoresSobrecargados.h"
#include <cstring>

void AbrirArchivos(ifstream& archClientes,ifstream& archProductos,ifstream& archPedidos,ofstream& archReportePrueba) {
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "ArchivosDeEntrada/Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "ArchivosDeEntrada/Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "ArchivosDeEntrada/Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(archReportePrueba, "ArchivosDeSalida/ReportePrueba.txt");
}

void ProbarSobrecargas( ifstream& archClientes, ifstream& archProductos, ifstream& archPedidos
    , ofstream& archReportePrueba) {
    Cliente arregloClientes[5];
    Producto arregloProductos[5];
    Pedido pedidos[5];

    CargarArreglos(archClientes,archProductos,archPedidos,arregloClientes,arregloProductos,pedidos);

    ImprimirPrueba(archReportePrueba,arregloClientes[0],arregloProductos[0],pedidos[0]);

    strcpy(arregloProductos[0].codigo, pedidos[0].codigoProducto);
    arregloClientes[0].dni=pedidos[0].dniCliente;
    arregloProductos+=pedidos[0];
    arregloClientes+=pedidos[0];

    ImprimirPrueba(archReportePrueba,arregloClientes[0],arregloProductos[0],pedidos[0]);
}

void CargarArreglos(ifstream& archClientes,ifstream& archProductos,ifstream& archPedidos,Cliente* arregloClientes
    ,Producto* arregloProductos,Pedido* pedidos) {
    archClientes>>arregloClientes[0];
    archProductos>>arregloProductos[0];
    archPedidos>>pedidos[0];
    arregloClientes[1].dni=0;
    strcpy(arregloProductos[1].codigo, "XXXXXXX");
}

void ImprimirPrueba(ofstream& archReportePrueba,const Cliente& cliente,const Producto& producto,const Pedido& pedido) {
    archReportePrueba<<cliente<<producto;
    archReportePrueba<<fixed<<setprecision(2);
    archReportePrueba<<left<<setw(10)<<pedido.codigoProducto<<right<<pedido.dniCliente;
    archReportePrueba<<setw(10)<<pedido.precioProducto<<endl;
}
