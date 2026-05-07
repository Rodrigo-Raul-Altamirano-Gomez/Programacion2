//
// Created by hrodic on 7/05/2026.
//
#include "Nota.h"
#include "FuncionesAuxliares.h"

void Nota::setCodigoCurso(const char *cadena) {
    if (cadena) this->codCurso=CopiarCadenaExacta(cadena);
    else this->codCurso=nullptr;
}

void Nota::setCiclo(int ciclo) {
    this->ciclo=ciclo;
}

void Nota::setNota(int nota) {
    this->nota=nota;
}

const char *Nota::getCodigoCurso() const {
    return this->codCurso;
}

int Nota::getCiclo() const {
    return this->ciclo;
}

int Nota::getNota() const {
    return this->nota;
}

