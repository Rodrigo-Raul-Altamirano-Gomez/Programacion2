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

void Presencial::imprime(ofstream &archReporte) const {
    Alumno::imprime(archReporte);
    archReporte<<setw(12)<<this->recargo<<setw(12)<<this->total;
}
