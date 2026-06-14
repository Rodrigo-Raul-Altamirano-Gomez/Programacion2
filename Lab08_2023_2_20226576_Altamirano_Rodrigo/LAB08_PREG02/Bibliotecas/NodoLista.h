//
// Created by hrodic on 12/06/2026.
//

#ifndef LAB08_PREG01_NODOLISTA_H
#define LAB08_PREG01_NODOLISTA_H
#include "Vehiculo.h"

class NodoLista {
    Vehiculo* unidad;
    NodoLista* sig;
    friend class LVehiculos;
public:
    NodoLista();
    ~NodoLista();
};


#endif //LAB08_PREG01_NODOLISTA_H
