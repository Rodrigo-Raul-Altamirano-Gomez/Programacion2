//
// Created by hrodic on 22/06/2026.
//

#include "NVehiculo.h"

NVehiculo::NVehiculo() {
    this->unidad=nullptr;
}

NVehiculo::NVehiculo(const NVehiculo &nvehiculo) : NVehiculo() {
    *this=nvehiculo;
}

NVehiculo &NVehiculo::operator=(const NVehiculo &n_vehiculo) {
    if (this!=&n_vehiculo) {
        this->unidad=n_vehiculo.unidad->clonar();
    }
    return *this;
}

Vehiculo *&NVehiculo::operator*() {
    return this->unidad;
}

NVehiculo::~NVehiculo() {
    delete this->unidad;
}
