//
// Created by hrodic on 12/06/2026.
//

#ifndef LAB08_PREG01_NPEDIDO_H
#define LAB08_PREG01_NPEDIDO_H

#include <fstream>
using namespace std;

class NPedido {
    char* codigo;
    int cantidad;
    double peso;
    NPedido* sig;
    friend class Vehiculo;
    void imprimir(ofstream&) const;
public:
    NPedido();
    ~NPedido();
};


#endif //LAB08_PREG01_NPEDIDO_H
