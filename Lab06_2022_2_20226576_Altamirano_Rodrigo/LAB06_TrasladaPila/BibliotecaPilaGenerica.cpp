//
// Created by hrodic on 3/05/2026.
//
#include <cstdlib>
#include "BibliotecaPilaGenerica.h"

void cargaarreglo(void*& arreglo,int (*cmp)(const void*,const void*),bool (*leeDato)(void*&,ifstream&)
    ,const char* nombreArchivoLectura) {
    ifstream archLectura(nombreArchivoLectura,ios::in);
    void *dato,*bufferDatos[30];
    int cantDatos=0;
    while (leeDato(dato,archLectura)) {
        bufferDatos[cantDatos]=dato;
        cantDatos++;
    }
    arreglo=new void*[cantDatos+1]{};
    void** regArreglo=(void**)arreglo;
    for (int i=0;i<cantDatos;i++) regArreglo[i]=bufferDatos[i];
    qsort(arreglo,cantDatos,sizeof(void*),cmp);
}

void cargapila(void*& pilaini,void* arreglo) {
    void** regArreglo=(void**)arreglo;
    int* cantInicial=new int(0);
    pilaini=nullptr;
    push(cantInicial,pilaini);
    for (int i=0;regArreglo[i];i++) push(regArreglo[i],pilaini);
}

bool pilavacia(void* pilaini) {
    if (pilaini) return false;
    else return true;
}

void push(void* dato,void*& pila) {
    void** nuevoNodo=new void*[2];
    nuevoNodo[1]=dato;
    if (pilavacia(pila)) {
        pila=nuevoNodo;
        nuevoNodo[0]=nullptr;
    }
    else {
        void** regNodoPrincipal=(void**)pila;
        nuevoNodo[0]=regNodoPrincipal[0];
        regNodoPrincipal[0]=nuevoNodo;
        int* cantActual=(int*)regNodoPrincipal[1];
        (*cantActual)++;
    }
}

void muevepila(void* pilaini,void*& pilafin) {
    void* pilaAux;
    void** regNodoPrincipalPilaIni=(void**)pilaini;
    int* cantInicial1=new int(0);
    int* cantInicial2=new int(0);
    int cantDatosPilaIni=*(int*)regNodoPrincipalPilaIni[1];
    pilaAux=nullptr;
    pilafin=nullptr;
    push(cantInicial1,pilaAux);
    push(cantInicial2,pilafin);
    Hanoi(cantDatosPilaIni,pilaini,pilaAux,pilafin);
}

void Hanoi(int n,void* origen,void* auxiliar,void* destino) {
    void* dato;
    if (n==1) {
        dato=pop(origen);
        push(dato,destino);
    }
    else {
        Hanoi(n-1,origen,destino,auxiliar);
        dato=pop(origen);
        push(dato,destino);
        Hanoi(n-1,auxiliar,origen,destino);
    }
}

void* pop(void* origen) {
    void** regNodoPrincipal=(void**)origen;
    void** regPrimerNodo=(void**)regNodoPrincipal[0];
    void* dato=regPrimerNodo[1];
    int* cantActual=(int*)regNodoPrincipal[1];
    regNodoPrincipal[0]=regPrimerNodo[0];
    *cantActual--;
    delete[] regPrimerNodo;
    return dato;
}

void imprimepila(void* pilafin,void (*imprimeDato)(void*,ofstream&),const char* nombreArchivoEscritura) {
    ofstream archEscritura(nombreArchivoEscritura,ios::out);
    void** regNodoPrincipal=(void**)pilafin;
    void** regNodoActual=(void**)regNodoPrincipal[0];
    while (regNodoActual) {
        imprimeDato(regNodoActual[1],archEscritura);
        regNodoActual=(void**)regNodoActual[0];
    }
}