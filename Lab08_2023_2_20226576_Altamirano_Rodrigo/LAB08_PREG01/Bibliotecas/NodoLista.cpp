//
// Created by hrodic on 12/06/2026.
//

#include "NodoLista.h"

NodoLista::NodoLista() {
    this->unidad=nullptr;
    this->sig=nullptr;
}

NodoLista::~NodoLista() {
    delete this->unidad;
    delete this->sig;
}
