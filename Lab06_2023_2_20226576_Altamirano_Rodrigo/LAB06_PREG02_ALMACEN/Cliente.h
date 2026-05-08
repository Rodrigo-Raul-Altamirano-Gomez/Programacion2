//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB06_PREG01_CLASES_CLIENTE_H
#define LAB06_PREG01_CLASES_CLIENTE_H

#include "ProductoEntregado.h"
#include <fstream>
using namespace std;

class Pedido;

class Cliente {
    int dni;
    char* nombre;
    int telefono;
    ProductoEntregado productos_entregados[20];
    int cantidad_productos_entregados;
    double monto_total;
public:
    friend bool operator>>(ifstream&,Cliente&);
    void operator+=(const Pedido&);
    friend ofstream& operator<<(ofstream&,const Cliente&);
    friend int BuscarCliente(const Cliente*,int,int);
};


#endif //LAB06_PREG01_CLASES_CLIENTE_H
