//
// Created by hrodic on 8/06/2026.
//

#ifndef INFRACCIONES2021_1LAB09_REGISTRO_H
#define INFRACCIONES2021_1LAB09_REGISTRO_H

#include "Conductor.h"
#include "Falta.h"
#include "Infraccion.h"

class Registro : public Conductor, public Falta {
    Infraccion* pfalta;
public:
    Registro();
    void leeConductor(int);
    void leeInfraccion(int);
    void imprimir(ofstream&) const;
    ~Registro();
};


#endif //INFRACCIONES2021_1LAB09_REGISTRO_H
