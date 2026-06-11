//
// Created by hrodic on 8/06/2026.
//

#ifndef INFRACCIONES2021_1LAB09_MUYGRAVE_H
#define INFRACCIONES2021_1LAB09_MUYGRAVE_H

#include "Infraccion.h"

class MuyGrave : public Infraccion {
    int puntos;
    int meses;
public:
    void lee(ifstream&,int) override;
};


#endif //INFRACCIONES2021_1LAB09_MUYGRAVE_H
