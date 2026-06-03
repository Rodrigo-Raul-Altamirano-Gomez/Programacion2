//
// Created by hrodic on 9/05/2026.
//
#include <cstring>
#include "Infraccion.h"

Infraccion::Infraccion() {
    this->descripcion=nullptr;
    this->gravedad=nullptr;
}

ifstream& operator>>(ifstream& archInfracciones,Infraccion& infraccion) {
    int codigo;
    if (archInfracciones>>codigo) {
        char descripcion[200],gravedad[200];
        double multa;
        archInfracciones.ignore();
        archInfracciones.getline(descripcion,200,',');
        archInfracciones.getline(gravedad,200,',');
        archInfracciones>>multa;
        infraccion.setCodigo(codigo);
        infraccion.setDescripcion(descripcion);
        infraccion.setGravedad(gravedad);
        infraccion.setMulta(multa);
    }
    return archInfracciones;
}

void Infraccion::setCodigo(int codigo) {
    this->codigo=codigo;
}

void Infraccion::setDescripcion(const char *descripcion) {
    delete[] this->descripcion;
    this->descripcion=new char[strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
}

void Infraccion::setGravedad(const char *gravedad) {
    delete[] this->gravedad;
    this->gravedad=new char[strlen(gravedad)+1];
    strcpy(this->gravedad,gravedad);
}

void Infraccion::setMulta(double multa) {
    this->multa=multa;
}

int Infraccion::getCodigo() const {
    return this->codigo;
}

const char *Infraccion::getGravedad() const {
    return this->gravedad;
}

double Infraccion::getMulta() const {
    return this->multa;
}

Infraccion::~Infraccion() {
    delete[] this->descripcion;
    delete[] this->gravedad;
    this->descripcion=nullptr;
    this->gravedad=nullptr;
}
