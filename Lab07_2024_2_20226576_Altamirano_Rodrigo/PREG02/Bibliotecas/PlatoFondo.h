//
// Created by hrodic on 4/06/2026.
//

#ifndef PREG01_PLATOFONDO_H
#define PREG01_PLATOFONDO_H

#include "Producto.h"

class PlatoFondo : public Producto{
    int* proteina;
public:
    PlatoFondo();
    PlatoFondo(const PlatoFondo&);
    PlatoFondo& operator=(const PlatoFondo&);
    void set_proteina(const int*);
    void leer(ifstream&);
    void imprimir(ofstream&) const;
    ~PlatoFondo();
};

ifstream& operator>>(ifstream&,PlatoFondo&);
ofstream& operator<<(ofstream&,const PlatoFondo&);

#endif //PREG01_PLATOFONDO_H
