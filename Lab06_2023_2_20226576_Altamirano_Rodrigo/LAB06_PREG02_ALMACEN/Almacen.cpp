//
// Created by hrodic on 7/05/2026.
//
#include "Pedido.h"
#include "Almacen.h"
#include <iomanip>

void Almacen::cargar_clientes() {
    ifstream archClientes("Clientes.csv",ios::in);
    this->cantidad_clientes=0;
    while (archClientes>>this->arreglo_clientes[this->cantidad_clientes]) this->cantidad_clientes++;
}

void Almacen::cargar_productos() {
    ifstream archProductos("Productos.csv",ios::in);
    this->cantidad_productos=0;
    while (archProductos>>this->arreglo_productos[this->cantidad_productos]) this->cantidad_productos++;
}

void Almacen::cargar_pedidos() {
    ifstream archPedidos("Pedidos.csv",ios::in);
    Pedido pedido;
    while (archPedidos>>pedido) {
        int posProducto=BuscarProducto(this->arreglo_productos,this->cantidad_productos,pedido.getCodigo());
        int posCliente=BuscarCliente(this->arreglo_clientes,this->cantidad_clientes,pedido.getDni());
        if (posProducto>=0 and posCliente>=0) {
            if (this->arreglo_productos[posProducto]+=pedido) this->arreglo_clientes[posCliente]+=pedido;
        }
    }
}

void Almacen::mostrar_datos() {
    ofstream archReporte("Reporte.txt",ios::out);
    archReporte<<setw(80)<<"Productos"<<endl;
    for (int i=0;i<this->cantidad_productos;i++) archReporte<<this->arreglo_productos[i];
    archReporte<<setw(80)<<"Clientes"<<endl;
    for (int i=0;i<this->cantidad_clientes;i++) archReporte<<this->arreglo_clientes[i];
}
