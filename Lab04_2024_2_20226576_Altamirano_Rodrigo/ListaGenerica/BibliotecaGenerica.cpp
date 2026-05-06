//
// Created by hrodic on 30/04/2026.
//

#include "BibliotecaGenerica.h"

void crealista(void*& lista,bool (*leeDato)(void*&,ifstream&),const char* nombreArchLectura) {
    ifstream archLectura(nombreArchLectura,ios::in);
    void* dato;
    construir(lista);
    while (leeDato(dato,archLectura)) insertafinal(dato,lista);
}

void construir(void*& lista) {
    lista=new void*[3]{};
    void** regLista=(void**)lista;
    regLista[2]=new int(0);
}

void insertafinal(void* dato,void* lista) {
    void** nuevaDupla=new void*[2]{dato};
    nuevaDupla[1]=new void*[20]{};
    void** nuevoNodo=new void*[2]{nuevaDupla,nullptr};
    void** regLista=(void**)lista;
    if (eslistavacia(lista)) regLista[0]=nuevoNodo;
    else {
        void** nodoFinal=(void**)regLista[1];
        nodoFinal[1]=nuevoNodo;
    }
    regLista[1]=nuevoNodo;
    (*(int*)regLista[2])++;
}

bool eslistavacia(void* lista) {
    void** regLista=(void**)lista;
    if (*(int*)regLista[2]==0) return true;
    else return false;
}

void cargalista(void* lista,void* (*comprueDato)(void*,void*),bool (*leeDato)(void*&,void*&,ifstream&)
    ,const char* nombreArchivoLectura) {
    ifstream archLectura(nombreArchivoLectura,ios::in);
    void *dato,*clave;
    while (leeDato(clave,dato,archLectura)) {
        void** arregloDupla=(void**)comprueDato(clave,lista);
        int cantDatosArreglo=0;
        for (int i=0;arregloDupla[i];i++) cantDatosArreglo++;
        arregloDupla[cantDatosArreglo]=dato;
        delete[] (void**)clave;
    }
}

void muestralista(void* lista,void (*imprimeDato)(void*,ofstream&),const char* nombreArchivoEscritura) {
    ofstream archEscritura(nombreArchivoEscritura,ios::out);
    void** regLista=(void**)lista;
    void** regNodoActual=(void**)regLista[0];
    for (int i=0;i<*(int*)regLista[2];i++) {
        imprimeDato(regNodoActual[0],archEscritura);
        regNodoActual=(void**)regNodoActual[1];
    }
}