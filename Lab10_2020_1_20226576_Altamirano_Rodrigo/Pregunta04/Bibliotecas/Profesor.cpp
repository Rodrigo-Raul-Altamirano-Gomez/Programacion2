#include <iomanip>
//
// Created by hrodic on 21/06/2026.
//
using namespace std;
#include "Profesor.h"

string Profesor::getCategoria() const {
    return this->categoria;
}

string Profesor::getDedicacion() const {
    return this->dedicacion;
}

string Profesor::getSeccion() const {
    return this->seccion;
}

string Profesor::getGrado() const {
    return this->grado;
}

void Profesor::leer(ifstream &archMiembros) {
    Persona::leer(archMiembros);
    getline(archMiembros,this->categoria,',');
    getline(archMiembros,this->dedicacion,',');
    getline(archMiembros,this->seccion,',');
    getline(archMiembros,this->grado);
}

void Profesor::imprimir(ofstream &archReporte) const {
    Persona::imprimir(archReporte);
    archReporte<<setw(20)<<this->categoria<<setw(20)<<this->dedicacion<<setw(20)<<this->seccion;
    archReporte<<this->grado;
}