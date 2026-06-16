//
// Created by hrodic on 14/06/2026.
//

#include "Entrada.h"

#include <cstring>
#include <iomanip>

Entrada::Entrada(const Entrada &entrada) : Entrada() {
    *this=entrada;
}

Entrada &Entrada::operator=(const Entrada &entrada) {
    if (this!=&entrada) {
        Producto::operator=(entrada);
        this->picante=entrada.picante;
    }
    return *this;
}

Producto *Entrada::clonar() const {
    Entrada* entradaClonada=new Entrada(*this);
    return entradaClonada;
}

void Entrada::leer(ifstream &archComandas) {
    char picante[30];
    Producto::leer(archComandas);
    archComandas.getline(picante,30);
    if (strcmp(picante,"picante")==0) this->picante=true;
    else this->picante=false;
}

int Entrada::getProteina() const {
    return -1;
}

void Entrada::imprimir(ofstream &archReporte) const {
    Producto::imprimir(archReporte);
    archReporte<<setw(10)<<" ";
    if (this->picante) archReporte<<"Picante"<<endl;
    else archReporte<<"Sin picante"<<endl;
}
