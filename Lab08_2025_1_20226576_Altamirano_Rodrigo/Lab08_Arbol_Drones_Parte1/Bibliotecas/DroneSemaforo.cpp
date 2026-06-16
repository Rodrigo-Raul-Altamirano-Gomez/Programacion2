//
// Created by hrodic on 15/06/2026.
//

#include "DroneSemaforo.h"

#include <cstring>
#include <iomanip>

void DroneSemaforo::leer(ifstream &archDrones) {
    char luz_roja[10];
    Dron::leer(archDrones);
    archDrones>>luz_roja;
    archDrones.ignore();
    if (strcmp(luz_roja,"true")==0) this->luz_roja=1;
    else this->luz_roja=0;
}

void DroneSemaforo::imprimir(ofstream &archReporte) const {
    Dron::imprimir(archReporte);
    archReporte<<setw(12)<<this->luz_roja<<endl;
}
