//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_BEBIDA_H
#define PREG01_LAB08_BEBIDA_H
#include "Producto.h"


class Bebida : public Producto {
    char* tamano;
public:
    Bebida();
    Bebida(const Bebida&);
    Bebida& operator=(const Bebida&);
    void setTamano(const char*);
    Producto* clonar() const override;
    void leer(ifstream &) override;
    int getProteina() const override;
    void imprimir(ofstream &) const override;
    ~Bebida() override;
};


#endif //PREG01_LAB08_BEBIDA_H
