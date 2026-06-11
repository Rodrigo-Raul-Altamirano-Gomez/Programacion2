//
// Created by hrodic on 8/06/2026.
//

#include "Grave.h"

void Grave::lee(ifstream &archInfracciones, int codInfraccion) {
    char car;
    Infraccion::lee(archInfracciones, codInfraccion);
    archInfracciones>>this->descuento>>car>>this->puntos;
}
