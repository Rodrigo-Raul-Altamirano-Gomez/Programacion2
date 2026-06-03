//
// Created by hrodic on 10/05/2026.
//
#include <cstring>
#include "Curso.h"

Curso::Curso() {
    this->ccurso=nullptr;
}

Curso::Curso(const Curso &curso) : Curso() {
    *this=curso;
}

void Curso::asignar(const Curso &curso) {
    *this=curso;
}

Curso &Curso::operator=(const Curso &curso) {
    if (this!=&curso) {
        setCodigo(curso.ccurso);
        this->ciclo=curso.ciclo;
        this->nota=curso.nota;
        this->credito=curso.credito;
    }
    return *this;
}

void Curso::setCodigo(const char *codigo) {
    delete[] this->ccurso;
    this->ccurso=new char[strlen(codigo)+1];
    strcpy(this->ccurso,codigo);
}

bool Curso::compare(const Curso &curso) const {
    return *this==curso;
}

bool Curso::operator==(const Curso &curso) const {
    if (strcmp(this->ccurso,curso.ccurso)==0 and this->ciclo==curso.ciclo) return true;
    else return false;
}

int Curso::getCiclo() const {
    return this->ciclo;
}

int Curso::getNota() const {
    return this->nota;
}

double Curso::getCredito() const {
    return this->credito;
}

void Curso::setCiclo(int ciclo) {
    this->ciclo=ciclo;
}

void Curso::setNota(int nota) {
    this->nota=nota;
}

void Curso::setCreditos(double creditos) {
    this->credito=creditos;
}

Curso::~Curso() {
    delete[] this->ccurso;
    this->ccurso=nullptr;
}
