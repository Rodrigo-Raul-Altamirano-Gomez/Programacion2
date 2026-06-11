//
// Created by hrodic on 4/06/2026.
//

#ifndef PREG01_BEBIDA_H
#define PREG01_BEBIDA_H


#include "Producto.h"

class Bebida : public Producto {
    char* tamaño;
public:
    Bebida();
    Bebida(const Bebida&);
    Bebida& operator=(const Bebida&);
    void set_tamaño(const char*);
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~Bebida();
};

ifstream& operator>>(ifstream&,Bebida&);
ofstream& operator<<(ofstream&,const Bebida&);

#endif //PREG01_BEBIDA_H
