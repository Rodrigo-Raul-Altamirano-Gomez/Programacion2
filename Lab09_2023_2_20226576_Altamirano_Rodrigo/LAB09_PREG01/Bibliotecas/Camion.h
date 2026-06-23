//
// Created by hrodic on 22/06/2026.
//

#ifndef LAB09_PREG01_CAMION_H
#define LAB09_PREG01_CAMION_H
#include "Vehiculo.h"
#include <map>
#include "NPedido.h"

class Camion : public Vehiculo {
    int ejes;
    int llantas;
    std::map<int,NPedido> mdeposito;
public:
    Camion();
    void leer(std::ifstream &) override;
    Vehiculo* clonar() const override;
    void imprimir(std::ofstream &) override;
    ~Camion() override = default;
};


#endif //LAB09_PREG01_CAMION_H
