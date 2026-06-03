//
// Created by hrodic on 1/06/2026.
//
#include <cstring>
#include <iomanip>
#include "Streamer.h"

Streamer::Streamer() {
    this->cuenta=nullptr;
    this->categoria=nullptr;
}

Streamer::Streamer(const Streamer& streamer) : Streamer() {
    *this=streamer;
}

Streamer::Streamer(int id,const char* cuenta,int numSeguidores,const char* categoria) : Streamer() {
    this->id=id;
    this->setCuenta(cuenta);
    this->n_seguidores=numSeguidores;
    this->setCategoria(categoria);
}

Streamer& Streamer::operator=(const Streamer& streamer) {
    if (this!=&streamer) {
        this->setID(streamer.getID());
        this->setCuenta(streamer.getCuenta());
        this->setNumSeguidores(streamer.getNumSeguidores());
        this->setCategoria(streamer.getCategoria());
    }
    return *this;
}

void Streamer::setID(int id) {
    this->id=id;
}

void Streamer::setCuenta(const char* cuenta) {
    delete[] this->cuenta;
    this->cuenta=new char[strlen(cuenta)+1];
    strcpy(this->cuenta,cuenta);
}

void Streamer::setNumSeguidores(int numSeguidores) {
    this->n_seguidores=numSeguidores;
}

void Streamer::setCategoria(const char* categoria) {
    delete[] this->categoria;
    this->categoria=new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}

int Streamer::getID() const {
    return this->id;
}

char* Streamer::getCuenta() const {
    char* cuentaCopia=new char[strlen(this->cuenta)+1];
    strcpy(cuentaCopia,this->cuenta);
    return cuentaCopia;
}

int Streamer::getNumSeguidores() const {
    return this->n_seguidores;
}

char* Streamer::getCategoria() const {
    char* categoriaCopia=new char[strlen(this->categoria)+1];
    strcpy(categoriaCopia,this->categoria);
    return categoriaCopia;
}

void Streamer::leer(ifstream &archStreamers) {
    char car,cuenta[30],categoria[50];
    archStreamers>>this->id>>car;
    archStreamers.getline(cuenta,30,',');
    archStreamers.getline(categoria,50,',');
    archStreamers>>this->n_seguidores>>car;
    this->setCuenta(cuenta);
    this->setCategoria(categoria);
}

void Streamer::imprimir(ofstream &archReporte) const {
    archReporte<<left<<"[ST]CUENTA: "<<setw(15)<<this->cuenta<<right<<"| SEGUIDORES: ";
    archReporte<<setw(7)<<this->n_seguidores<<" | CATEGORIA: "<<left<<setw(15)<<this->categoria<<"| ";
}

Streamer::~Streamer() {
    delete[] this->cuenta;
    delete[] this->categoria;
}