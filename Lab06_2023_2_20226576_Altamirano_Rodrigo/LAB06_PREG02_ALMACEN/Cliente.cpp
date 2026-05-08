//
// Created by hrodic on 7/05/2026.
//
#include "FuncionesAuxiliares.h"
#include <iomanip>
#include "Pedido.h"
#include "Cliente.h"

bool operator>>(ifstream& archClientes,Cliente& cliente) {
    if (archClientes>>cliente.dni) {
        archClientes.ignore();
        cliente.nombre=LeerCadenaExacta(archClientes);
        archClientes>>cliente.telefono;
        cliente.monto_total=0;
        cliente.cantidad_productos_entregados=0;
        return true;
    }
    return false;
}

void Cliente::operator+=(const Pedido& pedido) {
    ProductoEntregado productoEntregado;
    productoEntregado.setCodigo(pedido.getCodigo());
    productoEntregado.setPrecio(pedido.getPrecio());
    this->productos_entregados[this->cantidad_productos_entregados]=productoEntregado;
    this->cantidad_productos_entregados++;
    this->monto_total+=pedido.getPrecio();
}

ofstream &operator<<(ofstream& archReporte,const Cliente& cliente) {
    archReporte<<fixed<<setprecision(2);
    archReporte<<setw(8)<<cliente.dni<<setw(4)<<" "<<left<<setw(40)<<cliente.nombre;
    archReporte<<right<<setw(12)<<cliente.telefono<<setw(9)<<cliente.monto_total<<" Productos entregados: ";
    if (cliente.cantidad_productos_entregados>0) {
        for (int i=0;i<cliente.cantidad_productos_entregados;i++) {
            ProductoEntregado productoeEntregado=cliente.productos_entregados[i];
            archReporte<<left<<setw(9)<<productoeEntregado.getCodigo();
        }
    }
    else archReporte<<"NO SE LE ENTREGARON PRODUCTOS.";
    archReporte<<endl;
    return archReporte;
}

int BuscarCliente(const Cliente* clientes,int cantClientes,int dni) {
    for (int i=0;i<cantClientes;i++) {
        if (clientes[i].dni==dni) return i;
    }
    return -1;
}
