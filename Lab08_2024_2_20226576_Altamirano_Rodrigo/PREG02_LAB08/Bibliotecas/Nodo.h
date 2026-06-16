//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_NODO_H
#define PREG01_LAB08_NODO_H
#include "DetalleComanda.h"


class Nodo {
    DetalleComanda dato;
    Nodo* sig;
    friend class Cola;
public:
    Nodo();
    ~Nodo();
};


#endif //PREG01_LAB08_NODO_H
