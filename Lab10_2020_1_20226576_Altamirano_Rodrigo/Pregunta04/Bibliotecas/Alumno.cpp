#include <iomanip>
//
// Created by hrodic on 21/06/2026.
//
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    this->escala=0;
}

int Alumno::getEscala() const {
    return this->escala;
}

string Alumno::getEspecialidad() const {
    return this->especialidad;
}

string Alumno::getFacultad() const {
    return this->facultad;
}

void Alumno::leer(ifstream &archMembros) {
    char car;
    Persona::leer(archMembros);
    archMembros>>this->escala>>car;
    getline(archMembros,this->especialidad,',');
    getline(archMembros,this->facultad);
}

void Alumno::imprimir(ofstream &archReporte) const {
    Persona::imprimir(archReporte);
    archReporte<<right<<setw(2)<<this->escala<<setw(5)<<" "<<left<<setw(30)<<this->especialidad;
    archReporte<<this->facultad;
}
