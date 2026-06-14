//
// Created by hrodic on 12/06/2026.
//
#include <iomanip>
#include "Furgon.h"

void Furgon::leer(ifstream &archVehiculos) {
    char car;
    Vehiculo::leer(archVehiculos);
    archVehiculos>>this->filas>>car>>this->puertas;
}

void Furgon::imprimir(ofstream &archReporte) const {
    Vehiculo::imprimir(archReporte);
    archReporte<<setw(20)<<" "<<"#Filas:"<<setw(18)<<this->filas<<endl;
    archReporte<<setw(20)<<" "<<"#Puertas:"<<setw(16)<<this->puertas<<endl;
    archReporte<<setw(20)<<" "<<"Pedidos:"<<endl;
    this->imprimirPedidos(archReporte);
}
