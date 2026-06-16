//
// Created by hrodic on 14/06/2026.
//

#include "Enciclopedia.h"

#include <iomanip>

Enciclopedia::Enciclopedia() {
    this->vigencia=1;
}

void Enciclopedia::lee(ifstream &archLibros) {
    char car;
    Libro::lee(archLibros);
    archLibros>>this->sku>>car>>this->anho;
}

void Enciclopedia::actualiza() {
    if (this->anho<=2020) this->vigencia=0;
}

void Enciclopedia::imprime(ofstream &archReporte) const {
    Libro::imprime(archReporte);
    archReporte<<setw(10)<<" "<<"SKU: "<<this->sku<<setw(7)<<"Año: "<<this->anho<<setw(12)<<"Vigencia: ";
    archReporte<<this->vigencia<<endl;
}
