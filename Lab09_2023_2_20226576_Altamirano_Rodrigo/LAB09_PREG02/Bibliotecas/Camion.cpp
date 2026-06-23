//
// Created by hrodic on 22/06/2026.
//

#include "Camion.h"
using namespace std;
#include <iomanip>

Camion::Camion() {
    this->ejes=0;
    this->llantas=0;
}

void Camion::leer(std::ifstream &archVehiculos) {
    char car;
    Vehiculo::leer(archVehiculos);
    archVehiculos>>this->ejes>>car>>this->llantas;
}

Vehiculo *Camion::clonar() const {
    return new Camion(*this);
}

bool Camion::disponible(double pesoPedido) const {
    return Vehiculo::disponible(pesoPedido) and this->mdeposito.size()+1<=5;
}

void Camion::cargadeposito(NPedido pedido) {
    this->mdeposito[this->mdeposito.size()+1]=pedido;
}

void Camion::imprimir(std::ofstream &archReporte) {
    Vehiculo::imprimir(archReporte);
    archReporte<<setw(20)<<"#Ejes:"<<this->ejes<<endl;
    archReporte<<setw(20)<<"#Llantas:"<<this->llantas<<endl;
    archReporte<<"Lista de Pedidos:"<<right<<endl;
    if (not this->mdeposito.empty()) {
        for (auto iterador=this->mdeposito.begin();iterador!=this->mdeposito.end();iterador++) {
            archReporte<<setw(3)<<(*iterador).first<<setw(3)<<" ";
            (*iterador).second.imprimir(archReporte);
            archReporte<<endl;
        }
    } else archReporte<<setw(5)<<" "<<"No hay pedidos para el cliente"<<endl;
}
