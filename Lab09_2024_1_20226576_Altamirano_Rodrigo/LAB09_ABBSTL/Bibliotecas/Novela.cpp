#include <iomanip>
//
// Created by hrodic on 23/06/2026.
//
using namespace std;
#include "Novela.h"

Libro *Novela::clonar() const {
    return new Novela(*this);
}

void Novela::leer(std::ifstream &archLibros) {
    Libro::leer(archLibros);
    getline(archLibros,this->autor);
}

void Novela::imprimir(std::ofstream &archReporte) const {
    Libro::imprimir(archReporte);
    archReporte<<setw(10)<<" "<<"Autor: "<<this->autor<<endl;
}
