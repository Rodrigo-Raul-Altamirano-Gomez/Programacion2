//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_ENTRADA_H
#define PREG01_LAB08_ENTRADA_H
#include "Producto.h"


class Entrada : public Producto {
    bool picante;
public:
    Entrada() = default;
    Entrada(const Entrada&);
    Entrada& operator=(const Entrada&);
    Producto* clonar() const override;
    void leer(ifstream &) override;
    void imprimir(ofstream &) const override;
};


#endif //PREG01_LAB08_ENTRADA_H
