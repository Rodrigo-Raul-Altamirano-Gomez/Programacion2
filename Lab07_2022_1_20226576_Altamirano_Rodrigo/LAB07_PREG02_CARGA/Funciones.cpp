//
// Created by hrodic on 9/05/2026.
//

#include "Funciones.h"

void cargarClientes(Cliente* arrClientes) {
    ifstream archClientes("clientes2.csv",ios::in);
    int cantClientes=0;
    while (archClientes>>arrClientes[cantClientes]) cantClientes++;
    arrClientes[cantClientes].setNombre(nullptr);
}

void cargarPedidos(Pedido* arrPedidos) {
    ifstream archPedidos("pedidos2.csv",ios::in);
    int cantPedidos=0;
    while (archPedidos>>arrPedidos[cantPedidos]) cantPedidos++;
    arrPedidos[cantPedidos].setNombre(nullptr);
}

void agregarPedidos(Cliente* arrClientes,const Pedido* arrPedidos) {
    for (int i=0;arrPedidos[i].getNombre();i++) {
        for (int j=0;arrClientes[j].getNombre();j++) {
            if (arrPedidos[i].getDni()==arrClientes[j].getDni()) {
                arrClientes[j]=arrPedidos[i];
                break;
            }
        }
    }
}

void eliminarPedidos(Cliente* arrClientes) {
    ifstream archEliminaciones("eliminar2.csv",ios::in);
    Pedido pedido;
    while (archEliminaciones>>pedido) {
        for (int i=0;arrClientes[i].getNombre();i++) {
            if (arrClientes[i]-=pedido) break;
        }
    }
    pedido.~Pedido();
}

void aplicarDescuentos(Cliente* arrClientes) {
    for (int i=0;arrClientes[i].getNombre();i++) {
        if (arrClientes[i].getCategoria()=='A') {
            arrClientes[i]/10;
        }
    }
}

void emitirReporte(const Cliente* arrClientes) {
    ofstream archReporte("Reporte.txt",ios::out);
    for (int i=0;arrClientes[i].getNombre();i++) {
        archReporte<<arrClientes[i];
    }
}