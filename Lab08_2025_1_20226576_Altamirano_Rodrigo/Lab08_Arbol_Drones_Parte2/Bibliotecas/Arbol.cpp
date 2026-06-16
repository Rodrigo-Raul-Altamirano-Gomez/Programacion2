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

void Arbol::contarDronesABB(int &cantDronesVelocidad, int &cantDronesSemaforo, int &cantDronesEstacionamiento) const {
    this->contarDrones(cantDronesVelocidad,cantDronesSemaforo,cantDronesEstacionamiento,this->raiz);
}

void Arbol::contarDrones(int &cantDronesVelocidad, int &cantDronesSemaforo, int &cantDronesEstacionamiento,
    Nodo *nodoActual) const {
    if (not nodoActual) return;
    if (nodoActual->dron->getTipo()=='V') cantDronesVelocidad++;
    else if (nodoActual->dron->getTipo()=='S') cantDronesSemaforo++;
    else cantDronesEstacionamiento++;
    this->contarDrones(cantDronesVelocidad,cantDronesSemaforo,cantDronesEstacionamiento,nodoActual->izq);
    this->contarDrones(cantDronesVelocidad,cantDronesSemaforo,cantDronesEstacionamiento,nodoActual->der);
}

void Arbol::actualizarABB(int cantDronSemaforoTotal, int cantDronEstacionamientoTotal) {
    int cantDronSemaforo=0,cantDronEstacionamiento=0;
    this->actualizar(cantDronSemaforo,cantDronEstacionamiento,cantDronSemaforoTotal,cantDronEstacionamientoTotal,
        this->raiz);
}

void Arbol::actualizar(int& cantDronSemaforo,int& cantDronEstacionamiento,int cantDronSemaforoTotal,
    int cantDronEstacionamientoTotal,Nodo *nodoActual) {
    if (not nodoActual) return;
    char tipoDron=nodoActual->dron->getTipo();
    if ((tipoDron=='S' and cantDronSemaforo<=cantDronSemaforoTotal) or (tipoDron=='E' and
        cantDronEstacionamiento<=cantDronEstacionamientoTotal)) {
        nodoActual->dron->actualizar();
        tipoDron=='S' ? cantDronSemaforo++:cantDronEstacionamiento++;
    }
    this->actualizar(cantDronSemaforo,cantDronEstacionamiento,cantDronSemaforoTotal,cantDronEstacionamientoTotal,
        nodoActual->izq);
    this->actualizar(cantDronSemaforo,cantDronEstacionamiento,cantDronSemaforoTotal,cantDronEstacionamientoTotal,
        nodoActual->der);
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
