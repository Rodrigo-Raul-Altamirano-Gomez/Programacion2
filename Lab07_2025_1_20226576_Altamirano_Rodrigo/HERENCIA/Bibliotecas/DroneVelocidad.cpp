//
// Created by hrodic on 3/06/2026.
//
#include <iomanip>
#include "DroneVelocidad.h"

int DroneVelocidad::get_velocidad_maxima() const {
    return this->velocidad_maxima_permitida;
}

void DroneVelocidad::leer(ifstream &arch) {
    Drone::leer(arch);
    arch>>this->velocidad_maxima_permitida;
    arch.ignore();
}

void DroneVelocidad::imprimir(ofstream &arch) const {
    arch<<setw(5)<<this->velocidad_maxima_permitida;
    Drone::imprimir(arch);
}

ifstream& operator>>(ifstream& arch,DroneVelocidad& dron_velocidad) {
    dron_velocidad.leer(arch);
    return arch;
}

ofstream& operator<<(ofstream& arch,const DroneVelocidad& dron_velocidad) {
    dron_velocidad.imprimir(arch);
    return arch;
}