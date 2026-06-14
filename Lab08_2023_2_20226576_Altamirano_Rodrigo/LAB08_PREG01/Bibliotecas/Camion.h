//
// Created by hrodic on 12/06/2026.
//

#ifndef LAB08_PREG01_CAMION_H
#define LAB08_PREG01_CAMION_H
#include "Vehiculo.h"


class Camion : public Vehiculo {
    int ejes;
    int llantas;
public:
    void leer(ifstream &) override;
    void imprimir(ofstream &) const override;
};


#endif //LAB08_PREG01_CAMION_H
