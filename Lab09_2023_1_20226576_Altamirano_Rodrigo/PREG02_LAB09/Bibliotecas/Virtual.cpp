//
// Created by hrodic on 11/06/2026.
//

#include "Virtual.h"

#include <cstring>
#include <iomanip>

Virtual::Virtual() {
    this->licencia=nullptr;
    this->total=0;
}

void Virtual::setLicencia(const char *licencia) {
    delete[] this->licencia;
    this->licencia=new char[strlen(licencia)+1];
    strcpy(this->licencia,licencia);
}

void Virtual::lee(ifstream &archAlumnos) {
    char licencia[50];
    Alumno::lee(archAlumnos);
    archAlumnos.getline(licencia,50);
    this->setLicencia(licencia);
}

void Virtual::actualizatotal(double totalBruto) {
    double total;
    this->total=100;
    total=totalBruto+this->total;
    Alumno::actualizatotal(total);
}

void Virtual::imprime(ofstream &archReporte) const {
    Alumno::imprime(archReporte);
    archReporte<<setw(7)<<" "<<left<<setw(12)<<this->licencia<<right<<setw(5)<<this->total;
}

Virtual::~Virtual() {
    delete[] this->licencia;
}
