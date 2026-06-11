//
// Created by hrodic on 4/06/2026.
//

#ifndef PREG01_ENTRADA_H
#define PREG01_ENTRADA_H

#include "Producto.h"

class Entrada : public Producto {
    bool picante;
public:
    void leer(ifstream&);
    void imprimir(ofstream&) const;
};

ifstream& operator>>(ifstream&,Entrada&);
ofstream& operator<<(ofstream&,const Entrada&);

#endif //PREG01_ENTRADA_H
