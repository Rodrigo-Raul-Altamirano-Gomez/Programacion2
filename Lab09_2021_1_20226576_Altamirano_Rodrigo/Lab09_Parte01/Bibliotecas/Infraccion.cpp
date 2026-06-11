//
// Created by hrodic on 8/06/2026.
//
#include <cstring>
#include "Infraccion.h"

Infraccion::Infraccion() {
    this->descripcion=nullptr;
}

void Infraccion::setDescripcion(const char *descripcion) {
    delete[] this->descripcion;
    this->descripcion=new char[strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
}

void Infraccion::lee(ifstream& archInfracciones,int codInfraccion) {
    char car,descripcion[200];
    this->codigo=codInfraccion;
    archInfracciones.ignore();
    archInfracciones.getline(descripcion,200,',');
    archInfracciones.ignore(20,',');
    archInfracciones>>this->multa>>car;
    this->setDescripcion(descripcion);
}

Infraccion::~Infraccion() {
    delete[] this->descripcion;
}
