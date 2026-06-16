//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_PLATOFONDO_H
#define PREG01_LAB08_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo : public Producto {
    int proteina;
public:
    PlatoFondo() = default;
    PlatoFondo(const PlatoFondo&);
    PlatoFondo& operator=(const PlatoFondo&);
    Producto* clonar() const override;
    void leer(ifstream &) override;
    void imprimir(ofstream &) const override;
};


#endif //PREG01_LAB08_PLATOFONDO_H
