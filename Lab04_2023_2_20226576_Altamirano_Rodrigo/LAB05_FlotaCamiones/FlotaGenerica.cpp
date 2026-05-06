//
// Created by hrodic on 30/04/2026.
//
#include <iomanip>
#include <iostream>
#include "FlotaGenerica.h"

void cargacamiones(void*& flota,int numcamiones,int pesomaximo,bool (*leePedido)(void*&,ifstream&)
    ,double (*calculaPeso)(void*),const char* nombreArchivoLectura) {
    ifstream archLectura(nombreArchivoLectura,ios::in);
    void *pedido;
    flota=new void*[numcamiones]{};
    void** regFlota=(void**)flota;
    while (leePedido(pedido,archLectura)) {
        int posCamion=BuscarCamionDisponible(flota,numcamiones,pesomaximo,pedido,calculaPeso);
        if (posCamion>=0) {
            if (pilavacia(regFlota[posCamion])) {
                double* pesoInicial=new double(calculaPeso(pedido));
                push(pesoInicial,regFlota[posCamion],calculaPeso);
            }
            push(pedido,regFlota[posCamion],calculaPeso);
        }
    }
}

int BuscarCamionDisponible(void* flota,int numcamiones,int pesomaximo,void* pedido,double (*calculaPeso)(void*)) {
    void** regFlota=(void**)flota;
    for (int i=0;i<numcamiones;i++) {
        if (pilavacia(regFlota[i])) return i;
        else {
            void** regNodoPrincipal=(void**)regFlota[i];
            if (*(double*)regNodoPrincipal[1]+calculaPeso(pedido)<=pesomaximo) return i;
        }
    }
    return -1;
}

bool pilavacia(void* pila) {
    if (not pila) return true;
    else return false;
}

void push(void* dato,void*& pilaCamion,double (*calculaPeso)(void*)) {
    void** nuevoNodo=new void*[2];
    if (pilavacia(pilaCamion)) {
        nuevoNodo[1]=dato;
        nuevoNodo[0]=nullptr;
    }
    else {
        void** regNodoPrincipal=(void**)pilaCamion;
        double pesoActual=*(double*)regNodoPrincipal[1];
        double* pesoActualizado=new double();
        if (regNodoPrincipal[0]) *pesoActualizado=pesoActual+calculaPeso(dato);
        else *pesoActualizado=pesoActual;
        nuevoNodo[1]=pesoActualizado;
        nuevoNodo[0]=pilaCamion;
        regNodoPrincipal[1]=dato;
    }
    pilaCamion=nuevoNodo;
}

void muestracamiones(void* flota,int numcamiones,void (*imprimeDato)(void*,ofstream&)
    ,const char* nombreArchivoEscritura) {
    ofstream archEscritura(nombreArchivoEscritura,ios::out);
    archEscritura<<fixed<<setprecision(2);
    void** regFlota=(void**)flota;
    for (int i=0;i<numcamiones;i++) {
        void** regNodoPrincipal=(void**)regFlota[i];
        archEscritura<<"Camion "<<setw(4)<<i+1<<" Peso: "<<setw(8)<<*(double*)regNodoPrincipal[1]<<endl;
        for (void** regNodoActual=(void**)regNodoPrincipal[0];regNodoActual;regNodoActual=(void**)regNodoActual[0]) {
            imprimeDato(regNodoActual[1],archEscritura);
        }
    }
}