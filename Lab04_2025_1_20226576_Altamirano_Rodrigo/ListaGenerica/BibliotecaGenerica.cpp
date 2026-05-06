//
// Created by hrodic on 27/04/2026.
//

#include "BibliotecaGenerica.h"

void creaLista(void*& lista,bool (*leeDato)(void*&,ifstream&),void (*clasificaDato)(void*,void*,void*&,void*&)
    ,const char* nombreArchivoLectura) {
    ifstream archLectura(nombreArchivoLectura,ios::in);
    generaLista(lista);
    void* dato;
    while (leeDato(dato,archLectura)) insertaLista(dato,clasificaDato,lista);
}

void generaLista(void*& lista) {
    lista=new void*[2];
    void** regLista=(void**)lista;
    regLista[1]=new void*[2]{};
    regLista[0]=new void*[2]{nullptr,regLista[1]};
}

void insertaLista(void* dato,void (*clasificaDato)(void*,void*,void*&,void*&),void* lista) {
    void *nodoBloque,*nodoOtroBloque;
    clasificaDato(dato,lista,nodoBloque,nodoOtroBloque);
    void **regNodoBloque=(void**)nodoBloque,**regNodoOtroBloque=(void**)nodoOtroBloque;
    if (not regNodoBloque[0]) regNodoBloque[0]=dato;
    else {
        void** nuevoNodo=new void*[2]{dato};
        void **nodoAnterior,**nodoActual=regNodoBloque;
        for (;nodoActual!=regNodoOtroBloque and nodoActual;nodoActual=(void**)nodoActual[1]) nodoAnterior=nodoActual;
        nodoAnterior[1]=nuevoNodo;
        nuevoNodo[1]=nodoActual;
    }
}

void imprimeLista(void* lista,void (*imprimeDato)(void*,ofstream&),const char* nombreArchivoEscritura) {
    ofstream archEscritura(nombreArchivoEscritura,ios::out);
    void** regLista=(void**)lista;
    for (void** nodoActual=(void**)regLista[0];nodoActual;nodoActual=(void**)nodoActual[1]) {
        imprimeDato(nodoActual[0],archEscritura);
    }
}
