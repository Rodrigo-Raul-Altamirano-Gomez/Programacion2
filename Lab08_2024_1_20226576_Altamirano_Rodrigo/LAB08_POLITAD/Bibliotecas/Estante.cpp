//
// Created by hrodic on 14/06/2026.
//

#include "Estante.h"

#include <iomanip>

Estante::Estante() {
    this->id=-1;
}

int Estante::getID() const {
    return this->id;
}

double Estante::getCapacidad() const {
    return this->capacidad;
}

double Estante::getPeso() const {
    return this->Llibros.getPeso();
}

bool Estante::leer(ifstream &archEstantes) {
    char tipoEstante,car;
    if (archEstantes>>tipoEstante) {
        this->clase=tipoEstante;
        archEstantes>>car>>this->id>>car>>this->capacidad;
        return true;
    }
    return false;
}

void Estante::insertarLibro(Libro *libro) {
    this->Llibros.insertar(libro);
}

void Estante::actualizarVigencia() {
    this->Llibros.actualizar();
}

void Estante::imprimir(ofstream &archReporte) const {
    archReporte<<setw(10)<<" "<<setfill('=')<<setw(60)<<" "<<setfill(' ')<<endl<<endl;
    archReporte<<setw(10)<<" "<<"Id: "<<this->id<<endl;
    archReporte<<setw(10)<<" "<<"Tipo: ";
    this->clase=='H' ? archReporte<<"Horizontal"<<endl:archReporte<<"Vertical"<<endl;
    archReporte<<setw(10)<<" "<<"Capacidad: "<<this->capacidad<<endl;
    archReporte<<setw(10)<<" "<<"Libros Contenidos:"<<endl;
    archReporte<<setw(10)<<" "<<setfill('=')<<setw(60)<<" "<<setfill(' ')<<endl;
    this->Llibros.imprimir(archReporte);
}
