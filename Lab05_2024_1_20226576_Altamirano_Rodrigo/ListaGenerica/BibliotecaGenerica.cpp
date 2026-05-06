//
// Created by hrodic on 30/04/2026.
//

#include "BibliotecaGenerica.h"

void crealista(void*& lista,bool (*leeDato)(void*&,ifstream&),const char* nombreArchivoLectura) {
    ifstream archLectura(nombreArchivoLectura,ios::in);
    void* dato;
    lista=new void*[2]{};
    while (leeDato(dato,archLectura)) {
        insertalista(dato,lista);
    }
}

void insertalista(void* dato,void* lista) {
    void** regLista=(void**)lista;
    void** nuevoNodo=new void*[2]{dato,nullptr};
    if (listavacia(lista)) regLista[0]=nuevoNodo;
    else {
        void** nodoFinal=(void**)regLista[1];
        nodoFinal[1]=nuevoNodo;
    }
    regLista[1]=nuevoNodo;
}

bool listavacia(void* lista) {
    void** regLista=(void**)lista;
    if (not regLista[0]) return true;
    else return false;
}

void imprimelista(void* lista,void (*imprimeDato)(void*,ofstream&),const char* nombreArchReporte) {
    ofstream archReporte(nombreArchReporte,ios::out);
    void** regLista=(void**)lista;
    void** regNodoActual=(void**)regLista[0];
    while (regNodoActual) {
        imprimeDato(regNodoActual[0],archReporte);
        regNodoActual=(void**)regNodoActual[1];
    }
}

void* quitalista(void* lista) {
    void** regLista=(void**)lista;
    void** regNodoInicial=(void**)regLista[0];
    if (not listavacia(lista)) {
        void* dato=regNodoInicial[0];
        regLista[0]=regNodoInicial[1];
        delete[] regNodoInicial;
        return dato;
    }
    else return nullptr;
}

void combinalista(void* lista1,void* lista2,void*& listafinal,int (*cmp)(void*,void*)) {
    listafinal=new void*[2]{};
    int comparacionAnterior=0;
    void *datoInicial1,*datoInicial2;
    while (not listavacia(lista1) or not listavacia(lista2)) {
        if (comparacionAnterior==0) {
            datoInicial1=quitalista(lista1);
            datoInicial2=quitalista(lista2);
        }
        else if (comparacionAnterior<0) datoInicial1=quitalista(lista1);
        else datoInicial2=quitalista(lista2);
        int comparacion=cmp(datoInicial1,datoInicial2);
        if (comparacion<=0) insertalista(datoInicial1,listafinal);
        else insertalista(datoInicial2,listafinal);
        comparacionAnterior=comparacion;
    }
}