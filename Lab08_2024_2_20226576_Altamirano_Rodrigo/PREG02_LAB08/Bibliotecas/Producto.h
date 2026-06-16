//
// Created by hrodic on 14/06/2026.
//

#ifndef PREG01_LAB08_PRODUCTO_H
#define PREG01_LAB08_PRODUCTO_H
#include <fstream>
using namespace std;

class Producto {
    char* nombre;
    double precio;
public:
    Producto();
    Producto(const Producto&);
    Producto& operator=(const Producto&);
    void setNombre(const char*);
    virtual Producto* clonar() const = 0;
    virtual void leer(ifstream&);
    virtual int getProteina() const = 0;
    virtual void imprimir(ofstream&) const;
    virtual ~Producto();
};


#endif //PREG01_LAB08_PRODUCTO_H
