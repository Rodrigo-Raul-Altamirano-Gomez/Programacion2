//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_COLA_H
#define PREG01_LAB08_COLA_H
#include "Nodo.h"


class Cola {
    int longitud;
    Nodo* cabeza;
    Nodo* cola;
public:
    Cola();
    int getLongitud() const;
    void encola(const DetalleComanda&);
    DetalleComanda desencola();
    ~Cola();
};


#endif //PREG01_LAB08_COLA_H
