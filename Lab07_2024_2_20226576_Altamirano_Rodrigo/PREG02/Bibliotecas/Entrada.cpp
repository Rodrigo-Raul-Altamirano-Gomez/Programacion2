//
// Created by hrodic on 4/06/2026.
//
#include <cstring>
#include "Entrada.h"

void Entrada::leer(ifstream &archComandas) {
    char picante[30];
    Producto::leer(archComandas);
    archComandas.getline(picante,30,'\n');
    if (strcmp(picante,"picante")==0) this->picante=true;
    else this->picante=false;
}

void Entrada::imprimir(ofstream &archReporte) const {
    Producto::imprimir(archReporte);
    archReporte<<" Picante: ";
    if (this->picante) archReporte<<"Picante.";
    else archReporte<<"Sin picante.";
}

ifstream& operator>>(ifstream& archComandas,Entrada& entrada) {
    entrada.leer(archComandas);
    return archComandas;
}

ofstream& operator<<(ofstream& archReporte,const Entrada& entrada) {
    entrada.imprimir(archReporte);
    return archReporte;
}