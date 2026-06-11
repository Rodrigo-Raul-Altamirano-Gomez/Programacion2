//
// Created by hrodic on 11/06/2026.
//

#include "Presencial.h"

#include <iomanip>

Presencial::Presencial() {
    this->total=0;
}

void Presencial::lee(ifstream &archAlumnos) {
    Alumno::lee(archAlumnos);
    archAlumnos>>this->recargo;
}

void Presencial::actualizatotal(double totalBruto) {
    double total;
    this->total=(this->recargo/100)*totalBruto;
    total=this->total+totalBruto;
    Alumno::actualizatotal(total);
}

void Presencial::imprime(ofstream &archReporte) const {
    Alumno::imprime(archReporte);
    archReporte<<setw(12)<<this->recargo<<setw(13)<<this->total;
}
