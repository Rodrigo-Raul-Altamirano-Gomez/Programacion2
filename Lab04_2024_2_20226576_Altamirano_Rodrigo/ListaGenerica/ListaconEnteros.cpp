//
// Created by hrodic on 30/04/2026.
//

#include "ListaconEnteros.h"

bool leenumeros(void*& entero,ifstream& archNumeros) {
    int numero;
    if (archNumeros>>numero) {
        int* numeroEntero=new int(numero);
        entero=numeroEntero;
        return true;
    }
    return false;
}

bool leeregnumeros(void*& numeroClave,void*& numero,ifstream& archNumeros) {
    int clave;
    if (archNumeros>>clave) {
        int *numClave=new int(clave),*numDato=new int;
        archNumeros>>*numDato;
        numeroClave=numClave;
        numero=numDato;
        return true;
    }
    return false;
}

void* compruebanumero(void* numeroClave,void* listaNumeros) {
    void** regListaNumeros=(void**)listaNumeros;
    void** regNodoActual=(void**)regListaNumeros[0];
    for (int i=0;i<*(int*)regListaNumeros[2];i++) {
        void** regDuplaActual=(void**)regNodoActual[0];
        if (*(int*)regDuplaActual[0]==*(int*)numeroClave) return regDuplaActual[1];
        regNodoActual=(void**)regNodoActual[1];
    }
    return nullptr;
}

void imprimenumeros(void* duplaNumeros,ofstream& archRepNumeros) {
    void** regDuplaNumeros=(void**)duplaNumeros;
    archRepNumeros<<*(int*)regDuplaNumeros[0]<<endl;
    void** regArregloNumeros=(void**)regDuplaNumeros[1];
    for (int i=0;regArregloNumeros[i];i++) archRepNumeros<<*(int*)regArregloNumeros[i]<<" ";
    archRepNumeros<<endl<<endl;
}
