//
// Created by hrodic on 3/06/2026.
//
#include <iomanip>
#include <cstring>
#include "DroneSemaforo.h"

int DroneSemaforo::get_luz_roja() const {
    return this->luz_roja;
}

void DroneSemaforo::leer(ifstream &arch) {
    char luz[20];
    Drone::leer(arch);
    arch.getline(luz,20,'\n');
    if (strcmp(luz,"true")==0) this->luz_roja=1;
    else this->luz_roja=0;
}

void DroneSemaforo::imprimir(ofstream &arch) const {
    arch<<setw(5)<<this->luz_roja;
    Drone::imprimir(arch);
}

ifstream& operator>>(ifstream& arch,DroneSemaforo& drone_semaforo) {
    drone_semaforo.leer(arch);
    return arch;
}

ofstream& operator<<(ofstream& arch,const DroneSemaforo& drone_semaforo) {
    drone_semaforo.imprimir(arch);
    return arch;
}