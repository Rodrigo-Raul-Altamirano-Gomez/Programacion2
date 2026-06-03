//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB06_PREG01_CLASES_PRODUCTO_H
#define LAB06_PREG01_CLASES_PRODUCTO_H

#include <fstream>
#include "Pedido.h"
using namespace std;

class Producto {
    char* codigo;
    char* descripcion;
    double precio;
    int stock;
    int clientes_servidos[20];
    int clientes_no_servidos[20];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
public:
    friend bool operator>>(ifstream&,Producto&);
    bool operator+=(Pedido&);
    friend ofstream& operator<<(ofstream&,const Producto&);
};


#endif //LAB06_PREG01_CLASES_PRODUCTO_H
