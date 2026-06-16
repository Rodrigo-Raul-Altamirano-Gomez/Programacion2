//
// Created by hrodic on 14/06/2026.
//

#include "Nodo.h"

Nodo::Nodo() {
    this->sig=nullptr;
}

Nodo::~Nodo() {
    delete this->sig;
}
