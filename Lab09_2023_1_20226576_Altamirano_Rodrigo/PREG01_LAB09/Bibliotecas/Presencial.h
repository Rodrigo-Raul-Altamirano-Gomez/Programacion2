//
// Created by hrodic on 11/06/2026.
//

#ifndef PREG01_LAB09_PRESENCIAL_H
#define PREG01_LAB09_PRESENCIAL_H

#include "Alumno.h"

class Presencial : public Alumno {
    double recargo;
    double total;
public:
    Presencial();
    void lee(ifstream&) override;
    void imprime(ofstream &) const override;
    ~Presencial() override = default;
};


#endif //PREG01_LAB09_PRESENCIAL_H
