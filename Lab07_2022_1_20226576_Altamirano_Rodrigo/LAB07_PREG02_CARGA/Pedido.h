//
// Created by hrodic on 8/05/2026.
//

#ifndef LAB07_PREG01_CLASES_PEDIDO_H
#define LAB07_PREG01_CLASES_PEDIDO_H

#include <fstream>
using namespace std;

class Pedido {
    int codigo;
    char* nombre;
    int cantidad;
    double precio;
    int dni;
    int fecha;
public:
    friend ifstream& operator>>(ifstream&,Pedido&);
    void setNombre(const char*);
    Pedido& operator=(const Pedido&);
    double getPrecio() const;
    int getDni() const;
    int getFecha() const;
    int getCodigo() const;
    ~Pedido();
    void setPrecio(double);
    void imprimirPedido(ofstream&) const;
    Pedido();
    char* getNombre() const;
};


#endif //LAB07_PREG01_CLASES_PEDIDO_H
