//
// Created by hrodic on 4/06/2026.
//
#include <cstring>
#include "Bebida.h"

Bebida::Bebida() {
    this->tamaño=nullptr;
}

Bebida::Bebida(const Bebida& bebida) : Bebida() {
    *this=bebida;
}

Bebida& Bebida::operator=(const Bebida& bebida) {
    if (this!=&bebida) {
        Producto::operator=(bebida);
        this->set_tamaño(bebida.tamaño);
    }
    return *this;
}

void Bebida::set_tamaño(const char *tamaño) {
    delete[] this->tamaño;
    this->tamaño=new char[strlen(tamaño)+1];
    strcpy(this->tamaño,tamaño);
}

void Bebida::leer(ifstream &archComandas) {
    char tamaño[30];
    Producto::leer(archComandas);
    archComandas.getline(tamaño,30,'\n');
    this->set_tamaño(tamaño);
}

void Bebida::imprimir(ofstream &archReporte) const {
    Producto::imprimir(archReporte);
    archReporte<<" Tamaño: "<<this->tamaño;
}

ifstream& operator>>(ifstream& archComandas,Bebida& bebida) {
    bebida.leer(archComandas);
    return archComandas;
}

ofstream& operator<<(ofstream& archReporte,const Bebida& bebida) {
    bebida.imprimir(archReporte);
    return archReporte;
}

Bebida::~Bebida() {
    delete[] this->tamaño;
}
