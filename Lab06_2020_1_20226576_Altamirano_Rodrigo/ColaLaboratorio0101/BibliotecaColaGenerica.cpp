//
// Created by hrodic on 26/04/2026.
//

#include "BibliotecaColaGenerica.h"

void creaCola(void*& cola,bool (*leeDato)(void*&,ifstream&),const char* nombreArchivo) {
    ifstream archLectura(nombreArchivo,ios::in);
    void* dato;
    cola=new void*[2]{};
    while (leeDato(dato,archLectura)) encola(dato,cola);
}

void encola(void* dato,void* cola) {
    void** regCola=(void**)cola;
    void** nuevoNodo=new void*[2];
    nuevoNodo[0]=dato;
    nuevoNodo[1]=nullptr;
    if (colaVacia(cola)) regCola[0]=nuevoNodo;
    else {
        void** nodoFinal=(void**)(regCola[1]);
        nodoFinal[1]=nuevoNodo;
    }
    regCola[1]=nuevoNodo;
}

bool colaVacia(void* cola) {
    void** regCola=(void**)cola;
    if (regCola[0]) return false;
    else return true;
}

void imprimir(void* cola,void (*imprimeDato)(void*,ofstream&),const char* nombreArchivo) {
    ofstream archEscritura(nombreArchivo,ios::out);
    void** regCola=(void**)cola;
    void** nodoActual=(void**)(regCola[0]);
    while (nodoActual) {
        imprimeDato(nodoActual[0],archEscritura);
        nodoActual=(void**)(nodoActual[1]);
    }
}

void* desencola(void* cola) {
    void** regCola=(void**)cola;
    void** nodoCabeza=(void**)(regCola[0]);
    void* dato=nodoCabeza[0];
    regCola[0]=nodoCabeza[1];
    if (not regCola[0]) regCola[1]=nullptr;
    delete[] nodoCabeza;
    return dato;
}
