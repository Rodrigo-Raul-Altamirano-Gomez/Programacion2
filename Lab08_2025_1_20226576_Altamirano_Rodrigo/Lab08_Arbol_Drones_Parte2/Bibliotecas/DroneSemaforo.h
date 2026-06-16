//
// Created by hrodic on 15/06/2026.
//

#ifndef LAB08_ARBOL_DRONES_PARTE1_DRONESEMAFORO_H
#define LAB08_ARBOL_DRONES_PARTE1_DRONESEMAFORO_H
#include "Dron.h"


class DroneSemaforo : public Dron {
    int luz_roja;
public:
    void leer(ifstream &) override;
    char getTipo() const override;
    void actualizar() override;
    void imprimir(ofstream &) const override;
};


#endif //LAB08_ARBOL_DRONES_PARTE1_DRONESEMAFORO_H
