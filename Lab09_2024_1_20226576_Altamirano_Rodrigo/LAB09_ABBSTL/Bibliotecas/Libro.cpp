#include <iomanip>
//
// Created by hrodic on 23/06/2026.
//
using namespace std;
#include "Libro.h"

double Libro::getPeso() const {
    return this->peso;
}

void Libro::leer(std::ifstream &archLibros) {
    char car;
    getline(archLibros,this->nombre,',');
    archLibros>>this->paginas>>car>>this->peso>>car;
}

void Libro::imprimir(std::ofstream &archReporte) const {
    archReporte<<setw(10)<<" "<<"Titulo: "<<this->nombre<<endl;
    archReporte<<setw(10)<<" "<<"Peso: "<<this->peso<<endl;
}
