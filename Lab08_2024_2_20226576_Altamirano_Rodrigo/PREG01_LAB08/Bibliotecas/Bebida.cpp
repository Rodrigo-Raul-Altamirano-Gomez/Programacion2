//
// Created by hrodic on 14/06/2026.
//

#include "Bebida.h"

#include <cstring>
#include <iomanip>

Bebida::Bebida() {
    this->tamano=nullptr;
}

Bebida::Bebida(const Bebida &bebida) : Bebida() {
    *this=bebida;
}

Bebida &Bebida::operator=(const Bebida &bebida) {
    if (this!=&bebida) {
        Producto::operator=(bebida);
        this->setTamano(bebida.tamano);
    }
    return *this;
}

void Bebida::setTamano(const char *tamano) {
    delete[] this->tamano;
    this->tamano=new char[strlen(tamano)+1];
    strcpy(this->tamano,tamano);
}

Producto *Bebida::clonar() const {
    Bebida* bebidaClonada=new Bebida(*this);
    return bebidaClonada;
}

void Bebida::leer(ifstream &archComandas) {
    char tamano[30];
    Producto::leer(archComandas);
    archComandas.getline(tamano,30);
    this->setTamano(tamano);
}

void Bebida::imprimir(ofstream &archReporte) const {
    Producto::imprimir(archReporte);
    archReporte<<setw(10)<<" "<<"Tamano: "<<this->tamano<<endl;
}

Bebida::~Bebida() {
    delete[] this->tamano;
}
