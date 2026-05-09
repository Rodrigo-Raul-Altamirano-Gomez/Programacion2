//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB07_PREG01_CLASES_CLIENTE_H
#define LAB07_PREG01_CLASES_CLIENTE_H

#include "Pedido.h"
#include <fstream>
using namespace std;

class Cliente {
    int dni;
    char categoria;
    char* nombre;
    Pedido lped[100];
    int numped;
    double total;
public:
    friend ifstream& operator>>(ifstream&,Cliente&);
    void setNombre(const char*);
    void operator=(const Pedido&);
    void operator-=(const Pedido&);
    int encontrarPedido(const Pedido&) const;
    void operator/(double);
    friend ofstream& operator<<(ofstream&,const Cliente&);
};


#endif //LAB07_PREG01_CLASES_CLIENTE_H
