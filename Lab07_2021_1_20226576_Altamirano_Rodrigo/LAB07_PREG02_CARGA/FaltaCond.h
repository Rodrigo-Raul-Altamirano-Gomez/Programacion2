//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG01_CLASES_FALTACOND_H
#define LAB07_PREG01_CLASES_FALTACOND_H

#include "Falta.h"

class FaltaCond {
    char* placa;
    int fecha;
    int codInf;
    double multa;
    char* gravedad;
public:
    FaltaCond();
    FaltaCond& operator=(const FaltaCond&);
    FaltaCond& operator=(const Falta&);
    void setPlaca(const char*);
    void setGravedad(const char*);
    int getCodigo() const;
    void setMulta(double);
    double getMulta() const;
    int getFecha() const;
    const char* getGravedad() const;
    const char* getPlaca() const;
    ~FaltaCond();
};


#endif //LAB07_PREG01_CLASES_FALTACOND_H
