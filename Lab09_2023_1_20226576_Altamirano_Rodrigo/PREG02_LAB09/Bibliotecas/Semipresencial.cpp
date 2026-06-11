//
// Created by hrodic on 11/06/2026.
//

#include "Semipresencial.h"

#include <iomanip>

Semipresencial::Semipresencial() {
    this->total=0;
}

void Semipresencial::lee(ifstream &archAlumnos) {
    Alumno::lee(archAlumnos);
    archAlumnos>>this->descuento;
}

void Semipresencial::actualizatotal(double totalBruto) {
    double total;
    this->total=(this->descuento/100)*totalBruto;
    total=totalBruto-this->total;
    Alumno::actualizatotal(total);
}

void Semipresencial::imprime(ofstream &archReporte) const {
    Alumno::imprime(archReporte);
    archReporte<<setw(12)<<this->descuento<<setw(13)<<this->total;
}
