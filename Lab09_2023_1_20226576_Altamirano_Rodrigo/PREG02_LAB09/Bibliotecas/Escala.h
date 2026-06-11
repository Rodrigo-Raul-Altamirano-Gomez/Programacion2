//
// Created by hrodic on 11/06/2026.
//

#ifndef PREG01_LAB09_ESCALA_H
#define PREG01_LAB09_ESCALA_H


class Escala {
    int codigo;
    double precio;
public:
    Escala();
    void setCodigo(int);
    void setPrecio(double);
    int getCodigo() const;
    double getPrecio() const;
};


#endif //PREG01_LAB09_ESCALA_H
