//
// Created by hrodic on 22/06/2026.
//

#ifndef LAB09_PREG01_NVEHICULO_H
#define LAB09_PREG01_NVEHICULO_H
#include "Vehiculo.h"


class NVehiculo {
    Vehiculo* unidad;
public:
    NVehiculo();
    NVehiculo(const NVehiculo&);
    NVehiculo& operator=(const NVehiculo&);
    Vehiculo*& operator*();
    ~NVehiculo();
};


#endif //LAB09_PREG01_NVEHICULO_H
