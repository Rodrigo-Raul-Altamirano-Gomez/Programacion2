//
// Created by hrodic on 4/06/2026.
//

#ifndef PREG01_PRODUCTO_H
#define PREG01_PRODUCTO_H

#include <fstream>
using namespace std;

class Producto {
    char* nombre;
    double precio;
public:
    Producto();
    Producto(const Producto&);
    Producto& operator=(const Producto&);
    void set_nombre(const char*);
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~Producto();
};


#endif //PREG01_PRODUCTO_H
