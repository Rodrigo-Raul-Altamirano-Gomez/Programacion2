//
// Created by hrodic on 11/06/2026.
//

#ifndef PREG01_LAB09_SEMIPRESENCIAL_H
#define PREG01_LAB09_SEMIPRESENCIAL_H

#include "Alumno.h"

class Semipresencial : public Alumno {
    double descuento;
    double total;
public:
    Semipresencial();
    void lee(ifstream&) override;
    void actualizatotal(double) override;
    void imprime(ofstream &) const override;
    ~Semipresencial() override = default;
};


#endif //PREG01_LAB09_SEMIPRESENCIAL_H
