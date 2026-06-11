//
// Created by hrodic on 8/06/2026.
//
#include <cstring>
#include "Falta.h"

Falta::Falta() {
    this->placa=nullptr;
}

void Falta::setFecha(int fecha) {
    this->fecha=fecha;
}

void Falta::setPlaca(const char *placa) {
    delete[] this->placa;
    this->placa=new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}

Falta::~Falta() {
    delete[] this->placa;
}
