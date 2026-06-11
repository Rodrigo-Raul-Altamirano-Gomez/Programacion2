//
// Created by hrodic on 3/06/2026.
//
#include <cstring>
#include <iomanip>
#include "Drone.h"

Drone::Drone() {
    this->id=nullptr;
    this->ubicacion=nullptr;
    this->cantidad_infracciones=0;
}

void Drone::set_id(const char *id) {
    delete[] this->id;
    this->id=new char[strlen(id)+1];
    strcpy(this->id,id);
}

void Drone::set_ubicacion(const char *ubicacion) {
    delete[] this->ubicacion;
    this->ubicacion=new char[strlen(ubicacion)+1];
    strcpy(this->ubicacion,ubicacion);
}

char* Drone::get_id() const {
    char* id_copia=new char[strlen(this->id)+1];
    strcpy(id_copia,this->id);
    return id_copia;
}

void Drone::insertar_infraccion(const Infraccion &infraccion) {
    this->infracciones[this->cantidad_infracciones]=infraccion;
    this->cantidad_infracciones++;
}

void Drone::obtener_multas(int &cantidad_multas, double &monto_total) {
    cantidad_multas+=this->cantidad_infracciones;
    for (int i=0;i<this->cantidad_infracciones;i++) monto_total+=this->infracciones[i].get_monto();
}

void Drone::leer(ifstream &arch) {
    char id[20],ubicacion[50],car;
    arch.getline(id,20,',');
    arch.getline(ubicacion,50,',');
    arch>>this->capacidad>>car;
    this->set_id(id);
    this->set_ubicacion(ubicacion);
}

void Drone::imprimir(ofstream &arch) const {
    arch<<setw(4)<<" "<<left<<setw(12)<<this->id<<setw(30)<<this->ubicacion<<right<<setw(5)<<this->capacidad;
    arch<<setw(5)<<this->cantidad_infracciones<<endl;
    for (int i=0;i<this->cantidad_infracciones;i++) arch<<this->infracciones[i]<<endl;
}

Drone::~Drone() {
    delete[] this->id;
    delete[] this->ubicacion;
}
