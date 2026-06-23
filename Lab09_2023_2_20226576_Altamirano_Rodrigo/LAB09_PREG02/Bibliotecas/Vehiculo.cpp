#include <iomanip>
//
// Created by hrodic on 22/06/2026.
//
using namespace std;
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    this->cliente=0;
    this->maxcarga=0;
    this->actcarga=0;
}

void Vehiculo::setCliente(int cliente) {
    this->cliente=cliente;
}

void Vehiculo::setActCarga(double cargaActual) {
    this->actcarga=cargaActual;
}

int Vehiculo::getCliente() const {
    return this->cliente;
}

double Vehiculo::getCargaActual() const {
    return this->actcarga;
}

void Vehiculo::leer(std::ifstream &archVehiculos) {
    char car;
    archVehiculos>>this->cliente>>car;
    getline(archVehiculos,this->placa,',');
    archVehiculos>>this->maxcarga>>car;
}

bool Vehiculo::disponible(double pesoPedido) const {
    return this->actcarga+pesoPedido<=this->maxcarga;
}

void Vehiculo::imprimir(std::ofstream &archReporte) {
    archReporte<<left<<setw(20)<<"Codigo Cliente:"<<this->cliente<<endl;
    archReporte<<setw(20)<<"Placa:"<<this->placa<<endl;
    archReporte<<setw(20)<<"Carga Maxima:"<<this->maxcarga<<endl;
    archReporte<<setw(20)<<"Carga Actual:"<<this->actcarga<<endl;
}
