//
// Created by hrodic on 12/06/2026.
//

#include "Vehiculo.h"
#include <iomanip>
#include <cstring>

Vehiculo::Vehiculo() {
    this->placa=nullptr;
    this->actcarga=0;
    this->ped=nullptr;
}

void Vehiculo::setPlaca(const char *placa) {
    delete[] this->placa;
    this->placa=new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}

int Vehiculo::getCliente() const {
    return this->cliente;
}

double Vehiculo::getMaxCarga() const {
    return this->maxcarga;
}

double Vehiculo::getActCarga() const {
    return this->actcarga;
}

void Vehiculo::leer(ifstream &archVehiculos) {
    char car,placa[50];
    archVehiculos>>this->cliente>>car;
    archVehiculos.getline(placa,50,',');
    archVehiculos>>this->maxcarga>>car;
    this->setPlaca(placa);
}

void Vehiculo::push(const char *codProducto, int cantidad, double peso) {
    NPedido* nuevoNodo=new NPedido;
    nuevoNodo->setCodigo(codProducto);
    nuevoNodo->cantidad=cantidad;
    nuevoNodo->peso=peso;
    if (not this->pilavacia()) nuevoNodo->sig=this->ped;
    this->ped=nuevoNodo;
    this->actcarga+=peso;
}

bool Vehiculo::pilavacia() const {
    if (not this->ped) return true;
    else return false;
}

void Vehiculo::imprimir(ofstream &archReporte) const {
    archReporte<<setw(20)<<" "<<"Codigo Cliente:"<<setw(10)<<this->cliente<<endl;
    archReporte<<setw(20)<<" "<<"Placa:"<<setw(19)<<this->placa<<endl;
    archReporte<<setw(20)<<" "<<"Carga Maxima:"<<setw(12)<<this->maxcarga<<endl;
    archReporte<<setw(20)<<" "<<"Carga Actual:"<<setw(12)<<this->actcarga<<endl;
}

void Vehiculo::imprimirPedidos(ofstream &archReporte) const {
    if (not this->ped) archReporte<<setw(23)<<" "<<"No hay pedidos para el cliente."<<endl;
    else {
        for (const NPedido* nodoActual=this->ped;nodoActual;nodoActual=nodoActual->sig) {
            nodoActual->imprimir(archReporte);
        }
    }
}

Vehiculo::~Vehiculo() {
    delete[] this->placa;
    delete this->ped;
}
