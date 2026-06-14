//
// Created by hrodic on 12/06/2026.
//

#ifndef LAB08_PREG01_VEHICULO_H
#define LAB08_PREG01_VEHICULO_H

#include <fstream>
#include "NPedido.h"
using namespace std;


class Vehiculo {
    int cliente;
    char* placa;
    double maxcarga;
    double actcarga;
    NPedido* ped;
public:
    Vehiculo();
    void setPlaca(const char*);
    virtual void leer(ifstream&);
    virtual void imprimir(ofstream&) const;
    void imprimirPedidos(ofstream&) const;
    virtual ~Vehiculo();
};


#endif //LAB08_PREG01_VEHICULO_H
