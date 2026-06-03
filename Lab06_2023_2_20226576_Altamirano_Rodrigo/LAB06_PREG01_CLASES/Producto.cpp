//
// Created by hrodic on 7/05/2026.
//
#include "FuncionesAuxiliares.h"
#include <iomanip>
#include "Producto.h"

bool operator>>(ifstream& archProductos,Producto& producto) {
    producto.codigo=LeerCadenaExacta(archProductos);
    if (producto.codigo) {
        char car;
        producto.descripcion=LeerCadenaExacta(archProductos);
        archProductos>>producto.precio>>car>>producto.stock;
        archProductos.ignore();
        producto.cantidad_clientes_servidos=0;
        producto.cantidad_clientes_no_servidos=0;
        return true;
    }
    return false;
}

bool Producto::operator+=(Pedido& pedido) {
    pedido.setPrecio(this->precio);
    if (this->stock>0) {
        this->clientes_servidos[this->cantidad_clientes_servidos]=pedido.getDni();
        this->cantidad_clientes_servidos++;
        this->stock--;
        return true;
    }
    else {
        this->clientes_no_servidos[this->cantidad_clientes_no_servidos]=pedido.getDni();
        this->cantidad_clientes_no_servidos++;
        return false;
    }
}

ofstream &operator<<(ofstream& archReporte,const Producto& producto) {
    archReporte<<fixed<<setprecision(2);
    archReporte<<left<<setw(10)<<producto.codigo<<setw(50)<<producto.descripcion;
    archReporte<<right<<setw(9)<<producto.precio<<setw(7)<<producto.stock<<endl;
    archReporte<<left<<setw(25)<<"Clientes atendidos:"<<right;
    ImprimirClientes(producto.clientes_servidos,producto.cantidad_clientes_servidos,"NO SE ATENDIERON PEDIDOS."
        ,archReporte);
    archReporte<<endl<<left<<setw(25)<<"Clientes no atendidos:"<<right;
    ImprimirClientes(producto.clientes_no_servidos,producto.cantidad_clientes_no_servidos,"NO HAY CLIENTES SIN ATENDER"
        ,archReporte);
    archReporte<<endl;
    return archReporte;
}
