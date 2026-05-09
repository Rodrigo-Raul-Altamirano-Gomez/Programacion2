//
// Created by hrodic on 8/05/2026.
//
#include <cstring>
#include "Cliente.h"
#include <iomanip>

ifstream &operator>>(ifstream &archClientes, Cliente &cliente) {
    if (archClientes>>cliente.dni) {
        char nombre[200];
        archClientes.ignore();
        archClientes.getline(nombre,200,',');
        cliente.setNombre(nombre);
        archClientes>>cliente.categoria;
        cliente.numped=0;
        cliente.total=0;
    }
    return archClientes;
}

void Cliente::setNombre(const char *nombre) {
    if (nombre) {
        this->nombre=new char[strlen(nombre)+1];
        strcpy(this->nombre,nombre);
    }
    else this->nombre=nullptr;
}

void Cliente::operator=(const Pedido &pedido) {
    this->lped[this->numped]=pedido;
    this->numped++;
    this->total+=pedido.getPrecio();
}

bool Cliente::operator-=(const Pedido &pedido) {
    int posPedido=this->encontrarPedido(pedido);
    if (posPedido>=0) {
        for (int i=posPedido;i<this->numped-1;i++) {
            this->lped[i]=this->lped[i+1];
        }
        this->lped[this->numped-1].~Pedido();
        this->numped--;
        this->total-=pedido.getPrecio();
        return true;
    }
    else return false;
}

int Cliente::encontrarPedido(const Pedido &pedido) const {
    for (int i=0;i<this->numped;i++) {
        int dniActual=this->lped[i].getDni();
        int fechaActual=this->lped[i].getFecha();
        int codigoActual=this->lped[i].getCodigo();
        if (dniActual==pedido.getDni() and fechaActual==pedido.getFecha() and codigoActual==pedido.getCodigo()) {
            return i;
        }
    }
    return -1;
}

void Cliente::operator/(double descuento) {
    double nuevoTotal=0;
    for (int i=0;i<this->numped;i++) {
        double nuevoPrecio=(1-descuento/100)*this->lped[i].getPrecio();
        this->lped[i].setPrecio(nuevoPrecio);
        nuevoTotal+=nuevoPrecio;
    }
    this->total=nuevoTotal;
}

ofstream &operator<<(ofstream &archReporte, const Cliente &cliente) {
    archReporte<<left<<setw(30)<<cliente.dni<<cliente.nombre<<endl;
    archReporte<<setfill('=')<<setw(100)<<" "<<setfill(' ')<<endl;
    archReporte<<fixed<<setprecision(2);
    for (int i=0;i<cliente.numped;i++) cliente.lped[i].imprimirPedido(archReporte);
    archReporte<<"Monto Total: "<<cliente.total<<endl;
    return archReporte;
}

char *Cliente::getNombre() const {
    return this->nombre;
}

int Cliente::getDni() const {
    return this->dni;
}

char Cliente::getCategoria() const {
    return this->categoria;
}
