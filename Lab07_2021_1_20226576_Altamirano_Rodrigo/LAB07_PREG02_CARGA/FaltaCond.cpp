//
// Created by hrodic on 9/05/2026.
//
#include <cstring>
#include "FaltaCond.h"

FaltaCond::FaltaCond() {
    this->gravedad=nullptr;
    this->placa=nullptr;
}

FaltaCond &FaltaCond::operator=(const FaltaCond &faltaCond) {
    if (this!=&faltaCond) {
        setPlaca(faltaCond.placa);
        this->fecha=faltaCond.fecha;
        this->codInf=faltaCond.codInf;
    }
    return *this;
}

void FaltaCond::setPlaca(const char *placa) {
    delete[] this->placa;
    this->placa=new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}

void FaltaCond::setGravedad(const char *gravedad) {
    delete[] this->gravedad;
    this->gravedad=new char[strlen(gravedad)+1];
    strcpy(this->gravedad,gravedad);
}

FaltaCond &FaltaCond::operator=(const Falta &falta) {
    setPlaca(falta.getPlaca());
    this->codInf=falta.getCodigo();
    this->fecha=falta.getFecha();
    return *this;
}

int FaltaCond::getCodigo() const {
    return this->codInf;
}

void FaltaCond::setMulta(double multa) {
    this->multa=multa;
}

double FaltaCond::getMulta() const {
    return this->multa;
}

int FaltaCond::getFecha() const {
    return this->fecha;
}

const char *FaltaCond::getGravedad() const {
    return this->gravedad;
}

const char *FaltaCond::getPlaca() const {
    return this->placa;
}

FaltaCond::~FaltaCond() {
    delete[] this->placa;
    delete[] this->gravedad;
    this->placa=nullptr;
    this->gravedad=nullptr;
}
