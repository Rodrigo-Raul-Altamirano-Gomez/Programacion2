//
// Created by hrodic on 15/06/2026.
//

#include "DroneVelocidad.h"

#include <iomanip>

void DroneVelocidad::leer(ifstream &archDrones) {
    Dron::leer(archDrones);
    archDrones>>this->velocidad_maxima_permitida;
    archDrones.ignore();
}

char DroneVelocidad::getTipo() const {
    return 'V';
}

void DroneVelocidad::actualizar() {
    return;
}

void DroneVelocidad::imprimir(ofstream &archReporte) const {
    Dron::imprimir(archReporte);
    archReporte<<setw(12)<<this->velocidad_maxima_permitida<<endl;
}
