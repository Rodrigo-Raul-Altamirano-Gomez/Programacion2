//
// Created by hrodic on 11/06/2026.
//

#ifndef PREG01_LAB09_VIRTUAL_H
#define PREG01_LAB09_VIRTUAL_H

#include "Alumno.h"

class Virtual : public Alumno {
    char* licencia;
    double total;
public:
    Virtual();
    void setLicencia(const char*);
    void lee(ifstream &) override;
    void actualizatotal(double) override;
    void imprime(ofstream &) const override;
    ~Virtual() override;
};


#endif //PREG01_LAB09_VIRTUAL_H
