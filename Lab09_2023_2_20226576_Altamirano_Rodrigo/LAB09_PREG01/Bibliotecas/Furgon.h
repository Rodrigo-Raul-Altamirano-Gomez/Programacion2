//
// Created by hrodic on 22/06/2026.
//

#ifndef LAB09_PREG01_FURGON_H
#define LAB09_PREG01_FURGON_H
#include "Vehiculo.h"
#include <list>
#include "NPedido.h"

class Furgon : public Vehiculo {
    int filas;
    int puertas;
    std::list<NPedido> pdeposito;
public:
    Furgon();
    void leer(std::ifstream &) override;
    Vehiculo* clonar() const override;
    void imprimir(std::ofstream &) override;
    ~Furgon() override = default;
};


#endif //LAB09_PREG01_FURGON_H
