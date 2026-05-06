//
// Created by hrodic on 27/04/2026.
//

#include "BibliotecaEnteros.h"

bool leenum(void*& numero,ifstream& archNumeros) {
    int num;
    if (archNumeros>>num) {
        numero=new int(num);
        return true;
    }
    return false;
}

void clasificaentero(void* numero,void* lista,void*& nodoBloque,void*& nodoOtroBloque) {
    void** regLista=(void**)lista;
    if (*(int*)numero<10) {
        nodoBloque=regLista[0];
        nodoOtroBloque=regLista[1];
    }
    else {
        nodoBloque=regLista[1];
        nodoOtroBloque=regLista[0];
    }
}

void imprimenum(void* numero,ofstream& archRepNumeros) {
    if (numero)  archRepNumeros<<*(int*)numero<<endl;
}
