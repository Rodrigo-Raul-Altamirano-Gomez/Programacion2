//
// Created by hrodic on 8/05/2026.
//
#include <cstring>
#include "Pedido.h"
#include <iomanip>

ifstream &operator>>(ifstream &archPedidos, Pedido &pedido) {
    if (archPedidos>>pedido.codigo) {
        char nombre[200],car;
        int diaFecha,mesFecha,anioFecha;
        archPedidos.ignore();
        archPedidos.getline(nombre,200,',');
        pedido.setNombre(nombre);
        archPedidos>>pedido.cantidad>>car>>pedido.precio>>car>>pedido.dni>>car>>diaFecha>>car>>mesFecha>>car>>anioFecha;
        pedido.fecha=diaFecha+mesFecha*100+anioFecha*10000;
    }
    return archPedidos;
}

void Pedido::setNombre(const char *nombre) {
    delete[] this->nombre;
    if (nombre) {
        this->nombre=new char[strlen(nombre)+1];
        strcpy(this->nombre,nombre);
    }
    else this->nombre=nullptr;
}

Pedido& Pedido::operator=(const Pedido &pedido) {
    if (this!=&pedido) {
        this->codigo=pedido.codigo;
        this->setNombre(pedido.nombre);
        this->cantidad=pedido.cantidad;
        this->precio=pedido.precio;
        this->dni=pedido.dni;
        this->fecha=pedido.fecha;
    }
    return *this;
}

double Pedido::getPrecio() const {
    return this->precio;
}

int Pedido::getDni() const {
    return this->dni;
}

int Pedido::getFecha() const {
    return this->fecha;
}

int Pedido::getCodigo() const {
    return this->codigo;
}

Pedido::~Pedido() {
    delete[] this->nombre;
    this->nombre=nullptr;
}

void Pedido::setPrecio(double precio) {
    this->precio=precio;
}

void Pedido::imprimirPedido(ofstream &archReporte) const {
    int dia,mes,anio,res;
    anio=this->fecha/10000;
    res=this->fecha%10000;
    mes=res/100;
    dia=res%100;
    archReporte<<right<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'<<anio<<setfill(' ');
    archReporte<<setw(10)<<this->codigo<<setw(3)<<" "<<left<<setw(40)<<this->nombre;
    archReporte<<right<<setw(5)<<this->cantidad<<setw(8)<<this->precio<<endl;
}

Pedido::Pedido() {
    this->nombre=nullptr;
}

char *Pedido::getNombre() const {
    return this->nombre;
}
