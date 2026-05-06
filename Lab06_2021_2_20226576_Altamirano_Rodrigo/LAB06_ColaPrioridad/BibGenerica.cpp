//
// Created by hrodic on 4/05/2026.
//
#include <iomanip>
#include "BibGenerica.h"

void creacola(void*& cola,bool (*leeDato)(void*&,ifstream&),int (*prioridadDato)(void*)
    ,const char* nombreArchivoLectura) {
    ifstream archLectura(nombreArchivoLectura,ios::in);
    void* dato;
    cola=new void*[5]{};
    while (leeDato(dato,archLectura)) {
        int prioridad=prioridadDato(dato);
        encola(dato,prioridad,cola);
    }
}

void encola(void* dato,int prioridad,void*& cola) {
    void** nuevoNodo=new void*[2];
    void** regCola=(void**)cola;
    nuevoNodo[0]=dato;
    if (colavacia(cola)) {
        nuevoNodo[1]=nullptr;
        regCola[0]=nuevoNodo;
    }
    else {
        if (regCola[prioridad]) {
            void** nodoFinalPrioridad=(void**)regCola[prioridad];
            nuevoNodo[1]=nodoFinalPrioridad[1];
            nodoFinalPrioridad[1]=nuevoNodo;
        }
        else ColocarNodoPrioridadAnterior(nuevoNodo,prioridad,cola);
    }
    regCola[prioridad]=nuevoNodo;
    if (not nuevoNodo[1]) regCola[4]=nuevoNodo;
}

bool colavacia(void* cola) {
    void** regCola=(void**)cola;
    if (regCola[0]) return false;
    else return true;
}

void ColocarNodoPrioridadAnterior(void* nuevoNodo,int prioridad,void*& cola) {
    void* nodoPrioridadAnterior=nullptr;
    void** regCola=(void**)cola;
    void** regNuevoNodo=(void**)nuevoNodo;
    for (int i=prioridad-1;i>0;i--) {
        if (regCola[i]) {
            nodoPrioridadAnterior=regCola[i];
            break;
        }
    }
    if (nodoPrioridadAnterior) {
        void** regNodoAnterior=(void**)nodoPrioridadAnterior;
        regNuevoNodo[1]=regNodoAnterior[1];
        regNodoAnterior[1]=nuevoNodo;
    }
    else {
        regNuevoNodo[1]=regCola[0];
        regCola[0]=nuevoNodo;
    }
}

void descargarcola(void* cola,void (*muestraDato)(void*,ofstream&),const char* nombreArchivoEscritura) {
    ofstream archEscritura(nombreArchivoEscritura,ios::out);
    void** regCola=(void**)cola;
    int i=1;
    archEscritura<<left<<setw(8)<<"ORDEN"<<"DATO"<<endl;
    while (not colavacia(cola)) {
        void* dato=desencola(cola);
        archEscritura<<right<<setw(3)<<i<<setw(5)<<" ";
        muestraDato(dato,archEscritura);
        i++;
    }
}

void* desencola(void*& cola) {
    void** regCola=(void**)cola;
    void** regPrimerNodo=(void**)regCola[0];
    regCola[0]=regPrimerNodo[1];
    void* dato=regPrimerNodo[0];
    delete[] regPrimerNodo;
    return dato;
}