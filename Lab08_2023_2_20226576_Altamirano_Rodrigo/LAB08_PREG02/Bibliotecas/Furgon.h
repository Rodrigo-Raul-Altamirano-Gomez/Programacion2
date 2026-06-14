//
// Created by hrodic on 12/06/2026.
//

#ifndef LAB08_PREG01_FURGON_H
#define LAB08_PREG01_FURGON_H
#include "Vehiculo.h"


class Furgon : public Vehiculo {
    int filas;
    int puertas;
public:
    void leer(ifstream &) override;
    void imprimir(ofstream &) const override;
};


#endif //LAB08_PREG01_FURGON_H
