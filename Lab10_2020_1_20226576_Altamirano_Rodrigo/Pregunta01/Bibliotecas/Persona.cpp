#include <iomanip>
//
// Created by hrodic on 21/06/2026.
//
using namespace std;
#include "Persona.h"

Persona::Persona() {
    this->codigo=0;
}

string Persona::getNombre() const {
    return this->nombre;
}

int Persona::getCodigo() const {
    return this->codigo;
}

string Persona::getDistrito() const {
    return this->distrito;
}

void Persona::leer(ifstream& archMiembros) {
    char car;
    getline(archMiembros,this->nombre,',');
    archMiembros>>this->codigo>>car;
    getline(archMiembros,this->distrito,',');
}

void Persona::imprimir(ofstream& archReporte) const {
    archReporte<<left<<setw(10)<<this->codigo<<setw(30)<<this->nombre<<setw(30)<<this->distrito;
}

std::ifstream& operator>>(std::ifstream &archMiembros, Persona *persona) {
    persona->leer(archMiembros);
    return archMiembros;
}

std::ofstream &operator<<(std::ofstream &archReporte, const Persona *persona) {
    persona->imprimir(archReporte);
    return archReporte;
}
