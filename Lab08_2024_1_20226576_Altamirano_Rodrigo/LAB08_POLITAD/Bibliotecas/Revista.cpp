//
// Created by hrodic on 14/06/2026.
//

#include "Revista.h"

#include <iomanip>

Revista::Revista() {
    this->vigencia=1;
}

void Revista::lee(ifstream &archLibros) {
    char car;
    Libro::lee(archLibros);
    archLibros>>this->ISSN>>car>>this->anho>>car>>this->numero;
}

void Revista::actualiza() {
    if (this->anho<=2020) this->vigencia=0;
}

void Revista::imprime(ofstream &archReporte) const {
    Libro::imprime(archReporte);
    archReporte<<setw(10)<<" "<<"ISSN: "<<this->ISSN<<setw(10)<<"Año: "<<this->anho<<setw(10)<<"Numero: ";
    archReporte<<this->numero<<setw(12)<<"Vigencia: "<<this->vigencia<<endl;
}
