//
// Created by hrodic on 14/06/2026.
//

#include "Lista.h"

Lista::Lista() {
    this->peso=0;
    this->ini=nullptr;
}

double Lista::getPeso() const {
    return this->peso;
}

void Lista::insertar(Libro *libro) {
    Nodo* nuevoNodo=new Nodo;
    nuevoNodo->plibro=libro;
    if (this->ini) nuevoNodo->sig=this->ini;
    this->ini=nuevoNodo;
    this->peso+=libro->getPeso();
}

void Lista::actualizar() {
    for (Nodo* nodoActual=this->ini;nodoActual;nodoActual=nodoActual->sig) {
        nodoActual->plibro->actualiza();
    }
}

void Lista::imprimir(ofstream &archReporte) const {
    for (Nodo* nodoActual=this->ini;nodoActual;nodoActual=nodoActual->sig) {
        nodoActual->plibro->imprime(archReporte);
        archReporte<<endl;
    }
}

Lista::~Lista() {
    delete this->ini;
}
