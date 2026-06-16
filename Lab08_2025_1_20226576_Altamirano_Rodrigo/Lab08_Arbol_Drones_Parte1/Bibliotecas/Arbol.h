//
// Created by hrodic on 15/06/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
#define LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
#include "Nodo.h"


class Arbol {
    Nodo* raiz;
    void insertar(Dron*,Nodo*);
    void imprimir(ofstream&,Nodo*) const;
public:
    Arbol();
    void insertarABB(Dron*);
    void imprimirABB(ofstream&) const;
    ~Arbol();
};


#endif //LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
