//
// Created by hrodic on 14/06/2026.
//

#include "Novela.h"

#include <cstring>
#include <iomanip>

Novela::Novela() {
    this->autor=nullptr;
}

void Novela::setAutor(const char *autor) {
    delete[] this->autor;
    this->autor=new char[strlen(autor)+1];
    strcpy(this->autor,autor);
}

void Novela::lee(ifstream &archLibros) {
    char autor[50];
    Libro::lee(archLibros);
    archLibros.getline(autor,50);
    this->setAutor(autor);
}

void Novela::actualiza() {
    return;
}

void Novela::imprime(ofstream &archReporte) const {
    Libro::imprime(archReporte);
    archReporte<<setw(10)<<" "<<"Autor: "<<this->autor<<endl;
}

Novela::~Novela() {
    delete[] this->autor;
}
