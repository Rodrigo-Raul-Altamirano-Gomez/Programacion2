//
// Created by hrodic on 12/06/2026.
//

#ifndef LAB08_PREG01_LVEHICULOS_H
#define LAB08_PREG01_LVEHICULOS_H
#include "Vehiculo.h"
#include "NodoLista.h"

class LVehiculos {
    NodoLista* lini;
    NodoLista* lfin;
public:
    LVehiculos();
    void agregarVehiculo(Vehiculo*);
    void buscarAgregarPedido(int,const char*,int,double);
    void imprimir(ofstream&) const;
    ~LVehiculos();
};


#endif //LAB08_PREG01_LVEHICULOS_H
