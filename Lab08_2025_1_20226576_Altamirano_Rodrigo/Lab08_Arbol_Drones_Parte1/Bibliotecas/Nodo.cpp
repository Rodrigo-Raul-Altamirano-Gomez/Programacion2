//
// Created by hrodic on 15/06/2026.
//

#include "Nodo.h"

Nodo::Nodo() {
    this->dron=nullptr;
    this->izq=nullptr;
    this->der=nullptr;
}

Nodo::~Nodo() {
    delete this->dron;
    delete this->izq;
    delete this->der;
}
