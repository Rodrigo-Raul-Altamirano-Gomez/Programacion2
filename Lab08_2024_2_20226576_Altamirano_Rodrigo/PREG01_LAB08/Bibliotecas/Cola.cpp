//
// Created by hrodic on 14/06/2026.
//

#include "Cola.h"

Cola::Cola() {
    this->longitud=0;
    this->cabeza=nullptr;
    this->cola=nullptr;
}

int Cola::getLongitud() const {
    return this->longitud;
}

void Cola::encola(const DetalleComanda &detalle_comanda) {
    Nodo* nuevoNodo=new Nodo;
    nuevoNodo->dato=detalle_comanda;
    if (this->cabeza) this->cola->sig=nuevoNodo;
    else this->cabeza=nuevoNodo;
    this->cola=nuevoNodo;
    this->longitud++;
}

DetalleComanda Cola::desencola() {
    Nodo* nodo=this->cabeza;
    DetalleComanda detalle_comanda=nodo->dato;
    this->cabeza=nodo->sig;
    if (not this->cabeza) this->cola=nullptr;
    nodo->sig=nullptr;
    delete nodo;
    this->longitud--;
    return detalle_comanda;
}

Cola::~Cola() {
    delete this->cabeza;
}
