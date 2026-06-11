//
// Created by hrodic on 8/06/2026.
//

#include "Conductor.h"

Conductor::Conductor() {
    this->nombre=nullptr;
}

void Conductor::setLicencia(int licencia) {
    this->licencia=licencia;
}

void Conductor::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

Conductor::~Conductor() {
    delete[] this->nombre;
}
