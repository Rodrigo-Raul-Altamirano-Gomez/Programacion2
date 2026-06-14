//
// Created by hrodic on 12/06/2026.
//
#include <iomanip>
#include "Camion.h"

void Camion::leer(ifstream &archVehiculos) {
    char car;
    Vehiculo::leer(archVehiculos);
    archVehiculos>>this->ejes>>car>>this->llantas;
}

void Camion::imprimir(ofstream &archReporte) const {
    Vehiculo::imprimir(archReporte);
    archReporte<<setw(20)<<" "<<"#Ejes:"<<setw(19)<<this->ejes<<endl;
    archReporte<<setw(20)<<" "<<"#Llantas:"<<setw(16)<<this->llantas<<endl;
    archReporte<<setw(20)<<" "<<"Pedidos:"<<endl;
    this->imprimirPedidos(archReporte);
}
