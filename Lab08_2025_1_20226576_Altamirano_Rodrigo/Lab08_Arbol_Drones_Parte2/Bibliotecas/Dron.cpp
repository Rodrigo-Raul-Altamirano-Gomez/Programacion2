//
// Created by hrodic on 15/06/2026.
//

#include "Dron.h"

#include <cstring>
#include <iomanip>

Dron::Dron() {
    this->id=nullptr;
    this->ubicacion=nullptr;
}

void Dron::setID(const char *id) {
    delete[] this->id;
    if (id) {
        this->id=new char[strlen(id)+1];
        strcpy(this->id,id);
    }
    else this->id=nullptr;
}

void Dron::setUbicacion(const char *ubicacion) {
    delete[] this->ubicacion;
    if (ubicacion) {
        this->ubicacion=new char[strlen(ubicacion)+1];
        strcpy(this->ubicacion,ubicacion);
    }
    else this->ubicacion=nullptr;
}

void Dron::getID(char *id) const {
    strcpy(id,this->id);
}

void Dron::leer(ifstream &archDrones) {
    char id[20],ubicacion[45],car;
    archDrones.getline(id,20,',');
    archDrones.getline(ubicacion,45,',');
    this->setID(id);
    this->setUbicacion(ubicacion);
    archDrones>>this->capacidad>>car;
}

void Dron::imprimir(ofstream &archReporte) const {
    archReporte<<setw(5)<<" "<<left<<setw(10)<<this->id<<setw(15)<<this->ubicacion<<right;
    archReporte<<setw(7)<<this->capacidad;
}

Dron::~Dron() {
    delete[] this->id;
    delete[] this->ubicacion;
}
