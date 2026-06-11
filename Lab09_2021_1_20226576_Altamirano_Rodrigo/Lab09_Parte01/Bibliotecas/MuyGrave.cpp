//
// Created by hrodic on 8/06/2026.
//

#include "MuyGrave.h"

void MuyGrave::lee(ifstream &archInfracciones, int codInfraccion) {
    char car;
    Infraccion::lee(archInfracciones, codInfraccion);
    archInfracciones>>this->puntos>>car>>this->meses;
}
