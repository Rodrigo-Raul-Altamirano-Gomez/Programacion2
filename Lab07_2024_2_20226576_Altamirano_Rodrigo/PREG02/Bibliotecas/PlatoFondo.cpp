//
// Created by hrodic on 4/06/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    this->proteina=new int[4]{};
}

PlatoFondo::PlatoFondo(const PlatoFondo& plato_fondo) : PlatoFondo() {
    *this=plato_fondo;
}

PlatoFondo& PlatoFondo::operator=(const PlatoFondo& plato_fondo) {
    if (this!=&plato_fondo) {
        Producto::operator=(plato_fondo);
        this->set_proteina(plato_fondo.proteina);
    }
    return *this;
}

void PlatoFondo::set_proteina(const int *proteina) {
    delete[] this->proteina;
    this->proteina=new int[4];
    for (int i=0;i<4;i++) this->proteina[i]=proteina[i];
}

void PlatoFondo::leer(ifstream &archComandas) {
    char car;
    Producto::leer(archComandas);
    archComandas>>this->proteina[0]>>car>>this->proteina[1]>>car>>this->proteina[2]>>car>>this->proteina[3];
}

void PlatoFondo::imprimir(ofstream &archReporte) const {
    Producto::imprimir(archReporte);
    archReporte<<" Proteina: "<<this->proteina[0]<<','<<this->proteina[1]<<','<<this->proteina[2]<<',';
    archReporte<<this->proteina[3];
}

ifstream& operator>>(ifstream& archComandas,PlatoFondo& plato_fondo) {
    plato_fondo.leer(archComandas);
    return archComandas;
}

ofstream& operator<<(ofstream& archReporte,const PlatoFondo& plato_fondo) {
    plato_fondo.imprimir(archReporte);
    return archReporte;
}

PlatoFondo::~PlatoFondo() {
    delete[] this->proteina;
}