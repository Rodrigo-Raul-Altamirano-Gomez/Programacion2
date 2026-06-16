//
// Created by hrodic on 15/06/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
#define LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
#include "Nodo.h"


class Arbol {
    Nodo* raiz;
    void insertar(Dron*,Nodo*);
    void contarDrones(int&,int&,int&,Nodo*) const;
    void actualizar(int&,int&,int,int,Nodo *);
    void imprimir(ofstream&,Nodo*) const;
public:
    Arbol();
    void insertarABB(Dron*);
    void imprimirABB(ofstream&) const;
    void contarDronesABB(int&,int&,int&) const;
    void actualizarABB(int,int);
    ~Arbol();
};


#endif //LAB08_ARBOL_DRONES_PARTE1_ARBOL_H
