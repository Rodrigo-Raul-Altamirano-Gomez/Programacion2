//
// Created by hrodic on 14/06/2026.
//

#include "Libro.h"

#include <cstring>
#include <iomanip>

Libro::Libro() {
    this->nombre=nullptr;
}

void Libro::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

double Libro::getPeso() const {
    return this->peso;
}

void Libro::lee(ifstream &archLibros) {
    char nombre[100],car;
    archLibros.getline(nombre,100,',');
    this->setNombre(nombre);
    archLibros>>this->paginas>>car>>this->peso>>car;
}

void Libro::imprime(ofstream &archReporte) const {
    archReporte<<setw(10)<<" "<<"Titulo: "<<this->nombre<<endl;
    archReporte<<setw(10)<<" "<<"Peso: "<<this->peso<<endl;
}

Libro::~Libro() {
    delete[] this->nombre;
}
