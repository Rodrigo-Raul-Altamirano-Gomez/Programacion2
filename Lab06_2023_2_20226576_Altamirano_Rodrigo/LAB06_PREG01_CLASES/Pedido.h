//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB06_PREG01_CLASES_PEDIDO_H
#define LAB06_PREG01_CLASES_PEDIDO_H

#include <fstream>
using namespace std;

class Pedido {
    char* codigo;
    int dni_cliente;
    double precio_producto;
public:
    friend bool operator>>(ifstream&,Pedido&);
    const char* getCodigo() const;
    double getPrecio() const;
    void setPrecio(double);
    int getDni();
};


#endif //LAB06_PREG01_CLASES_PEDIDO_H
