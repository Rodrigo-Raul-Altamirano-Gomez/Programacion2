//
// Created by hrodic on 15/06/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_NODO_H
#define LAB08_ARBOL_DRONES_PARTE1_NODO_H
#include "Dron.h"


class Nodo {
    Dron* dron;
    Nodo* izq;
    Nodo* der;
    friend class Arbol;
public:
    Nodo();
    ~Nodo();
};


#endif //LAB08_ARBOL_DRONES_PARTE1_NODO_H
