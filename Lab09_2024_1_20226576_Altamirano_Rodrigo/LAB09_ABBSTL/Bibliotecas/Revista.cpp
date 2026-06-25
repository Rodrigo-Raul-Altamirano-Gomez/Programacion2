#include <iomanip>
//
// Created by hrodic on 23/06/2026.
//
using namespace std;
#include "Revista.h"

Libro *Revista::clonar() const {
    return new Revista(*this);
}

void Revista::leer(std::ifstream &archLibros) {
    char car;
    Libro::leer(archLibros);
    archLibros>>this->ISSN>>car>>this->anho>>car>>this->numero;
}

void Revista::imprimir(std::ofstream &archReporte) const {
    Libro::imprimir(archReporte);
    archReporte<<setw(10)<<" "<<"ISSN: "<<setw(12)<<this->ISSN<<"Año: "<<this->anho<<endl;
}
