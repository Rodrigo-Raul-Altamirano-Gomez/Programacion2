//
// Created by hrodic on 8/06/2026.
//

#ifndef INFRACCIONES2021_1LAB09_GRAVE_H
#define INFRACCIONES2021_1LAB09_GRAVE_H

#include "Infraccion.h"

class Grave : public Infraccion{
    double descuento;
    int puntos;
public:
    void lee(ifstream&,int) override;
};


#endif //INFRACCIONES2021_1LAB09_GRAVE_H
