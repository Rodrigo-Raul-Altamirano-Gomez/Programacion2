//
// Created by hrodic on 23/06/2026.
//

#include "Enciclopedia.h"
using namespace std;
#include <iomanip>

Libro *Enciclopedia::clonar() const {
    return new Enciclopedia(*this);
}

void Enciclopedia::leer(std::ifstream &archLibros) {
    char car;
    Libro::leer(archLibros);
    archLibros>>this->sku>>car>>this->anho;
}

void Enciclopedia::imprimir(std::ofstream &archReporte) const {
    Libro::imprimir(archReporte);
    archReporte<<setw(10)<<" "<<"SKU: "<<setw(12)<<this->sku<<"Año: "<<this->anho<<endl;
}
