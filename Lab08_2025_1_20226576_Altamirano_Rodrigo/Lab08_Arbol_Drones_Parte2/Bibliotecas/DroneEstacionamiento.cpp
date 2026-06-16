//
// Created by hrodic on 15/06/2026.
//

#include "DroneEstacionamiento.h"

#include <cstring>
#include <iomanip>

void DroneEstacionamiento::leer(ifstream &archDrones) {
    char zona_carga[10];
    Dron::leer(archDrones);
    archDrones>>zona_carga;
    archDrones.ignore();
    if (strcmp(zona_carga,"true")==0) this->zona_carga=1;
    else this->zona_carga=0;
}

char DroneEstacionamiento::getTipo() const {
    return 'E';
}

void DroneEstacionamiento::actualizar() {
    this->zona_carga=1;
}

void DroneEstacionamiento::imprimir(ofstream &archReporte) const {
    Dron::imprimir(archReporte);
    archReporte<<setw(12)<<this->zona_carga<<endl;
}
