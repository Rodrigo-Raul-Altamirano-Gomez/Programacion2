//
// Created by hrodic on 11/06/2026.
//

#include "Boleta.h"

#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    this->pboleta=nullptr;
}

bool Boleta::existe() const {
    if (this->pboleta) return true;
    else return false;
}

void Boleta::leer(ifstream &archAlumnos,int tipoAlumno) {
    if (tipoAlumno=='P') this->pboleta=new Presencial;
    else if (tipoAlumno=='S') this->pboleta=new Semipresencial;
    else this->pboleta=new Virtual;
    this->pboleta->lee(archAlumnos);
}

void Boleta::imprimir(ofstream &archReporte) const {
    this->pboleta->imprime(archReporte);
    archReporte<<endl;
}

Boleta::~Boleta() {
    delete this->pboleta;
}
