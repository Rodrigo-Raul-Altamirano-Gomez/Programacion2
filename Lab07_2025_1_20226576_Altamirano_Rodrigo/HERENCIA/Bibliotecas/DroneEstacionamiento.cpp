//
// Created by hrodic on 3/06/2026.
//
#include <iomanip>
#include <cstring>
#include "DroneEstacionamiento.h"

int DroneEstacionamiento::get_zona_carga() const {
    return this->zona_carga;
}

void DroneEstacionamiento::leer(ifstream &arch) {
    char zona[20];
    Drone::leer(arch);
    arch.getline(zona,20,'\n');
    if (strcmp(zona,"true")==0) this->zona_carga=1;
    else this->zona_carga=0;
}

void DroneEstacionamiento::imprimir(ofstream &arch) const {
    arch<<setw(5)<<this->zona_carga;
    Drone::imprimir(arch);
}

ifstream& operator>>(ifstream& arch,DroneEstacionamiento& drone_estacionamiento) {
    drone_estacionamiento.leer(arch);
    return arch;
}

ofstream& operator<<(ofstream& arch,const DroneEstacionamiento& drone_estacionamiento) {
    drone_estacionamiento.imprimir(arch);
    return arch;
}