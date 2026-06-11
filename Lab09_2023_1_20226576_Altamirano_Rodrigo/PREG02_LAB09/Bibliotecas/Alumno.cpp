//
// Created by hrodic on 11/06/2026.
//

#include "Alumno.h"

#include <cstring>
#include <iomanip>

Alumno::Alumno() {
    this->nombre=nullptr;
    this->total=0;
}

void Alumno::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

int Alumno::getEscala() const {
    return this->escala;
}

double Alumno::getCreditos() const {
    return this->creditos;
}

void Alumno::lee(ifstream &archAlumnos) {
    char car,nombre[75];
    archAlumnos>>this->codigo>>car;
    archAlumnos.getline(nombre,75,',');
    this->setNombre(nombre);
    archAlumnos>>this->escala>>car>>this->creditos>>car;
}

void Alumno::actualizatotal(double total) {
    this->total=total;
}

void Alumno::imprime(ofstream &archReporte) const {
    archReporte<<right<<setw(9)<<this->codigo<<setw(3)<<" "<<left<<setw(45)<<this->nombre<<right;
    archReporte<<setw(5)<<this->escala<<setw(12)<<this->creditos;
}

Alumno::~Alumno() {
    delete[] this->nombre;
}
