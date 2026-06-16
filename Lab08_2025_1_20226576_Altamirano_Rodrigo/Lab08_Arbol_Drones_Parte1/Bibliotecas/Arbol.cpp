//
// Created by hrodic on 15/06/2026.
//

#include "Arbol.h"

#include <cstring>

Arbol::Arbol() {
    this->raiz=nullptr;
}

void Arbol::insertarABB(Dron *dron) {
    this->insertar(dron,this->raiz);
}

void Arbol::insertar(Dron *dron,Nodo* nodo) {
    char idDronNodoActual[20],idDron[20];
    if (nodo) nodo->dron->getID(idDronNodoActual);
    else strcpy(idDronNodoActual,"000000");
    dron->getID(idDron);
    if (not nodo or (strcmp(idDronNodoActual,idDron)<0 and not nodo->der) or
        (strcmp(idDronNodoActual,idDron)>0 and not nodo->izq)) {
        Nodo* nuevoNodo=new Nodo;
        nuevoNodo->dron=dron;
        if (not nodo) this->raiz=nuevoNodo;
        else if (strcmp(idDronNodoActual,idDron)<0 and not nodo->der) nodo->der=nuevoNodo;
        else nodo->izq=nuevoNodo;
    }
    else if (strcmp(idDronNodoActual,idDron)<0) this->insertar(dron,nodo->der);
    else this->insertar(dron,nodo->izq);
}

void Arbol::imprimirABB(ofstream &archReporte) const {
    this->imprimir(archReporte,this->raiz);
}

void Arbol::imprimir(ofstream &archReporte, Nodo *nodoActual) const {
    if (not nodoActual) return;
    this->imprimir(archReporte,nodoActual->izq);
    nodoActual->dron->imprimir(archReporte);
    this->imprimir(archReporte,nodoActual->der);
}

Arbol::~Arbol() {
    delete this->raiz;
}
