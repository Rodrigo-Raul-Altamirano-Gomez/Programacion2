//
// Created by hrodic on 9/05/2026.
//
#include <cstring>
#include "Falta.h"

Falta::Falta() {
    this->placa=nullptr;
}

ifstream& operator>>(ifstream& archFaltas,Falta& falta) {
    int licencia,dia,mes,anio,codInfraccion,fechaInfraccion;
    if (archFaltas>>licencia) {
        char placa[200],car;
        archFaltas.ignore();
        archFaltas.getline(placa,200,',');
        archFaltas>>dia>>car>>mes>>car>>anio>>car>>codInfraccion;
        fechaInfraccion=dia+mes*100+anio*10000;
        falta.setLicencia(licencia);
        falta.setPlaca(placa);
        falta.setfecha(fechaInfraccion);
        falta.setCodigo(codInfraccion);
    }
    return archFaltas;
}

void Falta::setLicencia(int licencia) {
    this->licencia=licencia;
}

void Falta::setPlaca(const char *placa) {
    delete[] this->placa;
    this->placa=new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}

void Falta::setfecha(int fecha) {
    this->fecha=fecha;
}

void Falta::setCodigo(int codigo) {
    this->codInf=codigo;
}

const char *Falta::getPlaca() const {
    return this->placa;
}

int Falta::getCodigo() const {
    return this->codInf;
}

int Falta::getFecha() const {
    return this->fecha;
}

int Falta::getLicencia() const {
    return this->licencia;
}

Falta::~Falta() {
    delete[] this->placa;
    this->placa=nullptr;
}
