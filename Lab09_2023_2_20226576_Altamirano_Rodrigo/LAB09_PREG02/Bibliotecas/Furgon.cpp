//
// Created by hrodic on 22/06/2026.
//

#include "Furgon.h"
using namespace std;
#include <iomanip>

Furgon::Furgon() {
    this->filas=0;
    this->puertas=0;
}

void Furgon::leer(std::ifstream &archVehiculos) {
    char car;
    Vehiculo::leer(archVehiculos);
    archVehiculos>>this->filas>>car>>this->puertas;
}

Vehiculo *Furgon::clonar() const {
    return new Furgon(*this);
}

bool Furgon::disponible(double pesoPedido) const {
    return Vehiculo::disponible(pesoPedido);
}

void Furgon::cargadeposito(NPedido pedido) {
    this->pdeposito.push_front(pedido);
}

void Furgon::imprimir(std::ofstream &archReporte) {
    Vehiculo::imprimir(archReporte);
    archReporte<<setw(20)<<"#Filas:"<<this->filas<<endl;
    archReporte<<setw(20)<<"#Puertas:"<<this->puertas<<endl;
    archReporte<<"Lista de Pedidos:"<<endl;
    if (not this->pdeposito.empty()) {
        while (not this->pdeposito.empty()) {
            archReporte<<setw(3)<<" ";
            this->pdeposito.front().imprimir(archReporte);
            this->pdeposito.pop_front();
            archReporte<<endl;
        }
    } else archReporte<<"No hay pedidos para el cliente."<<endl;
}
