//
// Created by hrodic on 29/04/2026.
//

#include "BibliotecaGenerica.h"

void generaLista(void*& lista) {
    lista=new void*(nullptr);
}

void insertaLista(void* dato,int (*compara)(void*,void*),void* lista) {
    void** nuevoNodo=new void*[2]{dato};
    void** regLista=(void**)lista;
    void** nodoAnterior=nullptr;
    for (void** nodoActual=(void**)*regLista;nodoActual;nodoActual=(void**)nodoActual[1]) {
        if (compara(nodoActual[0],dato)>0) break;
        nodoAnterior=nodoActual;
    }
    if (not nodoAnterior) {
        if (not *regLista) nuevoNodo[1]=nullptr;
        else nuevoNodo[1]=*regLista;
        *regLista=nuevoNodo;
    }
    else {
        nuevoNodo[1]=nodoAnterior[1];
        nodoAnterior[1]=nuevoNodo;
    }
}

void creaLista(void* lista,bool (*leeDato)(void*&,ifstream&),int (*compara)(void*,void*)
    ,void* (*buscalista)(void*,void*),const char* nombreArchLectura) {
    ifstream archLectura(nombreArchLectura,ios::in);
    void* dato;
    while (leeDato(dato,archLectura)) {
        void** regDato=(void**)buscalista(dato,lista);
        if (regDato) insertaLista(dato,compara,regDato[3]);
        else insertaLista(dato,compara,lista);
    }
}

void imprimeLista(void* lista,void (*imprimeDato)(void*,ofstream&),const char* nombreArchEscritura) {
    ofstream archEscritura(nombreArchEscritura,ios::out);
    void** regLista=(void**)lista;
    for (void** regNodoActual=(void**)*regLista;regNodoActual;regNodoActual=(void**)regNodoActual[1]) {
        imprimeDato(regNodoActual[0],archEscritura);
    }
}