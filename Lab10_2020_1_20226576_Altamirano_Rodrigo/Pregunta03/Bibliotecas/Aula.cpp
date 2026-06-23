#include <iomanip>
//
// Created by hrodic on 21/06/2026.
//
using namespace std;
#include "Aula.h"

Aula::Aula() {
    this->capacidad=0;
    this->codigo=0;
    this->nombre="Sin asignar";
    this->tipo='S';
}

void Aula::leer(std::ifstream &archAulas) {
    getline(archAulas,this->clave,',');
    archAulas>>this->capacidad;
    archAulas.ignore();
}

void Aula::imprimir(std::ofstream &archReporte) const {
    archReporte<<"Aula: "<<this->clave<<endl;
    archReporte<<"Capacidad"<<this->capacidad<<endl;
    archReporte<<"Codigo: "<<this->codigo<<endl;
    archReporte<<"Nombre: "<<this->nombre<<endl;
    archReporte<<"Tipo: "<<this->tipo<<endl;
}

std::ifstream &operator>>(std::ifstream &archAulas, Aula &aula) {
    aula.leer(archAulas);
    return archAulas;
}

std::ofstream &operator<<(std::ofstream &archReporte, const Aula &aula) {
    aula.imprimir(archReporte);
    return archReporte;
}
