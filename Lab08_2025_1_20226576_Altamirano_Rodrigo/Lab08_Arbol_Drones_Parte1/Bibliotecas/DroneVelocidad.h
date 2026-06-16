//
// Created by hrodic on 15/06/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_DRONEVELOCIDAD_H
#define LAB08_ARBOL_DRONES_PARTE1_DRONEVELOCIDAD_H
#include "Dron.h"


class DroneVelocidad : public Dron {
    double velocidad_maxima_permitida;
public:
    void leer(ifstream &) override;
    void imprimir(ofstream &) const override;
};


#endif //LAB08_ARBOL_DRONES_PARTE1_DRONEVELOCIDAD_H
