//
// Created by hrodic on 5/04/2026.
//
#include "Funciones.h"
#include "AperturaDeArchivos.h"
#include "OperadoresSobrecargados.h"
#include <cstring>

void CargarArrClientes(Cliente* arregloClientes) {
    int cantClientes=0;
    ifstream archClientes;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "ArchivosDeEntrada/Clientes.csv");
    while (archClientes>>arregloClientes[cantClientes]) cantClientes++;
    arregloClientes[cantClientes].dni=0;
}

void CargarArrProductos(Producto* arregloProductos) {
    int cantProductos=0;
    ifstream archProductos;
    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "ArchivosDeEntrada/Productos.csv");
    while (archProductos>>arregloProductos[cantProductos]) cantProductos++;
    strcpy(arregloProductos[cantProductos].codigo,"XXXXXXX");
}

void ProcesarPedidos(Cliente* arregloClientes,Producto* arregloProductos) {
    Pedido pedido;
    ifstream archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "ArchivosDeEntrada/Pedidos.csv");
    while (archPedidos>>pedido) {
        arregloProductos+=pedido;
        arregloClientes+=pedido;
    }
}

void EmitirReporte(Cliente* arregloClientes,Producto* arregloProductos) {
    Cliente cliente;
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "ArchivosDeSalida/Reporte.csv");
    archReporte<<fixed<<setprecision(2);
    archReporte<<setw(80)<<"CLIENTES"<<endl;
    archReporte<<left<<setw(11)<<"DNI"<<setw(45)<<"NOMBRE"<<right<<setw(9)<<"TELEFONO";
    archReporte<<setw(15)<<"MONTO TOTAL"<<setw(4)<<" "<<"PRODUCTOS ENTREGADOS"<<endl;
    for (int cantClientes=0; arregloClientes[cantClientes].dni!=0; cantClientes++) {
        cliente=arregloClientes[cantClientes];
        archReporte<<right<<setfill('0')<<setw(8)<<cliente.dni<<setfill(' ')<<setw(3)<<" "<<left;
        archReporte<<setw(45)<<cliente.nombre<<right<<setfill('0')<<setw(9)<<cliente.telefono<<setfill(' ');
        archReporte<<setw(15)<<cliente.montoTotal<<setw(4)<<" "<<left;
        if (cliente.cantidadProductosEntregados>0) {
            for (int i=0; i<cliente.cantidadProductosEntregados; i++) {
                archReporte<<setw(10)<<cliente.productosEntregados[i].codigo;
            }
            archReporte<<endl;
        }
        else archReporte<<"NO SE LE ENTREGARON PRODUCTOS."<<endl;
    }
    ImprimirProductos(arregloProductos,archReporte);
}

void ImprimirProductos(Producto* arregloProductos,ofstream& archReporte) {
    Producto producto;
    archReporte<<right<<setw(80)<<"PRODUCTOS"<<endl;
    for (int cantProductos=0; strcmp(arregloProductos[cantProductos].codigo,"XXXXXXX")!=0; cantProductos++) {
        producto=arregloProductos[cantProductos];
        archReporte<<left<<setw(10)<<"CODIGO"<<setw(55)<<"DESCRIPCION"<<right<<setw(7)<<"PRECIO";
        archReporte<<setw(8)<<"STOCK"<<endl;
        archReporte<<left<<setw(10)<<producto.codigo<<setw(55)<<producto.descripcion;
        archReporte<<right<<setw(7)<<producto.precio<<setw(8)<<producto.stock<<endl;
        archReporte<<left<<setw(23)<<"Clientes atendidos:"<<right;
        ImprimirClientesServidosONoServidos(archReporte,producto.clientesServidos,producto.cantidadClientesServidos
            ,true);
        archReporte<<"Clientes no atendidos: ";
        ImprimirClientesServidosONoServidos(archReporte,producto.clientesNoServidos
            ,producto.cantidadClientesNoServidos,false);
    }

}

void ImprimirClientesServidosONoServidos(ofstream& archEscritura, const int* clientes, int cantidadClientes
    , bool servidos) {
    if (cantidadClientes>0) {
        for (int i=0; i<cantidadClientes; i++) {
            archEscritura<<clientes[i]<<setw(4)<<" ";
        }
        archEscritura<<endl;
    }
    else {
        servidos ? archEscritura<<"NO SE ATENDIERON PEDIDOS."<<endl:archEscritura<<"NO HAY CLIENTES SIN ATENDER."<<endl;
    }
}