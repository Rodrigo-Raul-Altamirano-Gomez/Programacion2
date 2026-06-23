//
// Created by hrodic on 22/06/2026.
//

#ifndef LAB09_PREG01_FLOTA_H
#define LAB09_PREG01_FLOTA_H
#include <vector>
#include "NVehiculo.h"

class Flota {
    std::vector<NVehiculo> vflota;
public:
    void cargaflota();
    void muestracarga();
};


#endif //LAB09_PREG01_FLOTA_H
