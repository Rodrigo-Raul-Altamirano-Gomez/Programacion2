//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_DETALLECOMANDA_H
#define PREG01_LAB08_DETALLECOMANDA_H
#include "Producto.h"
#include <fstream>
using namespace std;

class DetalleComanda {
    int id;
    Producto* pedido;
public:
    DetalleComanda();
    DetalleComanda(const DetalleComanda&);
    DetalleComanda& operator=(const DetalleComanda&);
    void setPedido(const Producto*);
    bool leer(ifstream&);
    void imprimir(ofstream&) const;
    ~DetalleComanda();
};


#endif //PREG01_LAB08_DETALLECOMANDA_H
