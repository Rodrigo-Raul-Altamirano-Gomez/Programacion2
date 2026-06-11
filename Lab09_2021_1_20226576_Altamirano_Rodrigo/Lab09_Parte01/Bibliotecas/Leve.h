//
// Created by hrodic on 8/06/2026.
//

#ifndef INFRACCIONES2021_1LAB09_LEVE_H
#define INFRACCIONES2021_1LAB09_LEVE_H

#include "Infraccion.h"

class Leve : public Infraccion {
    double descuento;
public:
    void lee(ifstream&,int) override;
};


#endif //INFRACCIONES2021_1LAB09_LEVE_H
