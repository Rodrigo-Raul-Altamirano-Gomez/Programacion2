//
// Created by hrodic on 9/05/2026.
//
#include <cstring>
#include "Medico.h"

Medico::Medico() {
    this->nombre=nullptr;
    this->codigo=0;
}

ifstream& operator>>(ifstream& archMedicos,Medico& medico) {
    int codigo;
    if (archMedicos>>codigo) {
        char buffer[200];
        double tarifa;
        archMedicos.ignore();
        archMedicos.getline(buffer,200,',');
        archMedicos>>tarifa;
        medico.setCodigo(codigo);
        medico.setNombre(buffer);
        medico.setTarifa(tarifa);
    }
    return archMedicos;
}

void Medico::setCodigo(int codigo) {
    this->codigo=codigo;
}

void Medico::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Medico::setTarifa(double tarifa) {
    this->tarifa=tarifa;
}

int Medico::getCodigo() const {
    return this->codigo;
}

double Medico::getTarifa() const {
    return this->tarifa;
}

Medico::~Medico() {
    delete[] this->nombre;
}
