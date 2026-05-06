//
// Created by hrodic on 27/04/2026.
//

#include "ListaGenerica.h"

void new_list(list& lista) {
    lista.size=0;
    lista.front=nullptr;
    lista.back=nullptr;
}

void push_front(list& lista,void* dato,void* (*clonarDato)(void*)) {
    void* datoClonado=clonarDato(dato);
    void** nuevoNodo=new void*[2]{datoClonado,lista.front};
    lista.front=nuevoNodo;
    if (not lista.front) lista.back=nuevoNodo;
    lista.size++;
}

void push_back(list& lista,void* dato,void* (*clonarDato)(void*)) {
    void* nuevoDato=clonarDato(dato);
    void** nuevoNodo=new void*[2]{nuevoDato,nullptr};
    if (lista.front) {
        void** nodoFin=(void**)lista.back;
        nodoFin[1]=nuevoNodo;
    }
    else lista.front=nuevoNodo;
    lista.back=nuevoNodo;
    lista.size++;
}

void* begin(list lista) {
    return lista.front;
}

void* end() {
    return nullptr;
}

void* next(void* nodoActual) {
    void** regNodoActual=(void**)nodoActual;
    return regNodoActual[1];
}

void* getValue(void* nodoActual) {
    void** regNodoActual=(void**)nodoActual;
    return regNodoActual[0];
}

void foreach(list lista,void (*procesarDato)(void*)) {
    void* nodoActual=begin(lista);
    while (nodoActual!=end()) {
        void* datoActual=getValue(nodoActual);
        procesarDato(datoActual);
        nodoActual=next(nodoActual);
    }
}

bool findIf(list lista,bool (*compare)(void*,void*),void* clave) {
    for (void* nodoActual=begin(lista);nodoActual!=end();nodoActual=next(nodoActual)) {
        void* datoActual=getValue(nodoActual);
        if (compare(datoActual,clave)) return true;
    }
    return false;
}