//
// Created by hrodic on 8/06/2026.
//

#include "Leve.h"

void Leve::lee(ifstream &archInfracciones, int codInfraccion) {
    Infraccion::lee(archInfracciones, codInfraccion);
    archInfracciones>>this->descuento;
}
