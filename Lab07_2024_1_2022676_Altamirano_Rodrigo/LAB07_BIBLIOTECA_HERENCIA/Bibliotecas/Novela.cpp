//
// Created by hrodic on 25/05/2026.
//

#include "Novela.h"

Novela::Novela() {
    this->tipo=nullptr;
}

Novela::Novela(const Novela &novela) : Novela() {
    *this=novela;
}

void Novela::leerNovela(ifstream &archLibro) {
    this->leerLibro(archLibro);
    this->tipo=this->leerCadena(archLibro);
    archLibro>>this->peso;
    this->setPeso(this->peso);
}

void Novela::setColocado(bool colocado) {
    Libro::setColocado(colocado);
}

int Novela::getAnchura() const {
    return Libro::getAnchura();
}

int Novela::getAltura() const {
    return Libro::getAltura();
}

double Novela::getPeso() const {
    return this->peso;
}

Novela &Novela::operator=(const Novela &novela) {
    if (this!=&novela) {
        Libro::operator=(novela);
        delete[] this->tipo;
        this->tipo=this->copiarCadena(novela.tipo);
        this->peso=novela.peso;
    }
    return *this;
}

void Novela::imprimirNovela(ofstream &archReporte) const {
    this->imprimirLibro(archReporte);
}

ifstream& operator>>(ifstream& archLibros,Novela& novela) {
    novela.leerNovela(archLibros);
    return archLibros;
}

ofstream& operator<<(ofstream& archReporte,const Novela& novela) {
    novela.imprimirNovela(archReporte);
    return archReporte;
}

Novela::~Novela() {
    delete[] this->tipo;
}
