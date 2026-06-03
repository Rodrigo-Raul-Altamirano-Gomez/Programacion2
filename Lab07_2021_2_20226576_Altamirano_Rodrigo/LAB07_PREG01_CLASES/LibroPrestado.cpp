//
// Created by hrodic on 10/05/2026.
//
#include <cstring>
#include <iomanip>
#include "LibroPrestado.h"

LibroPrestado::LibroPrestado() {
    this->codigoLib=nullptr;
}

ifstream& operator>>(ifstream& archPrestamos,LibroPrestado& libroPrestado) {
    int carne,dia,mes,anio,fechaRetiro;
    if (archPrestamos>>carne) {
        char tipo,car,codigo[20];
        archPrestamos>>tipo>>car;
        archPrestamos.getline(codigo,20,',');
        archPrestamos>>dia>>car>>mes>>car>>anio;
        fechaRetiro=dia+mes*100+anio*10000;
        libroPrestado.setCarne(carne);
        libroPrestado.setTipo(tipo);
        libroPrestado.setCodigoLib(codigo);
        libroPrestado.setFechaRetiro(fechaRetiro);
    }
    return archPrestamos;
}

void LibroPrestado::setCarne(int carne) {
    this->carne=carne;
}

void LibroPrestado::setTipo(char tipo) {
    this->tipo=tipo;
}

void LibroPrestado::setCodigoLib(const char *codigo) {
    delete[] this->codigoLib;
    this->codigoLib=new char[strlen(codigo)+1];
    strcpy(this->codigoLib,codigo);
}

void LibroPrestado::setFechaRetiro(int fecha) {
    this->fechaDeRetiro=fecha;
}

LibroPrestado &LibroPrestado::operator=(const LibroPrestado &libroPrestado) {
    if (this!=&libroPrestado) {
        this->carne=libroPrestado.carne;
        this->tipo=libroPrestado.tipo;
        setCodigoLib(libroPrestado.codigoLib);
        this->fechaDeRetiro=libroPrestado.fechaDeRetiro;
        this->deuda=libroPrestado.deuda;
    }
    return *this;
}

char LibroPrestado::getTipo() const {
    return this->tipo;
}

int LibroPrestado::getFechaRetiro() const {
    return this->fechaDeRetiro;
}

void LibroPrestado::setDeuda(int deuda) {
    this->deuda=deuda;
}

ofstream& operator<<(ofstream& archReporte,const LibroPrestado& libroPrestado) {
    int dia,mes,anio,res;
    anio=libroPrestado.getFecha()/10000,res=libroPrestado.getFecha()%10000,mes=res/100,dia=res%100;
    archReporte<<left<<setw(15)<<libroPrestado.getCodigo()<<right;
    archReporte<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'<<anio<<setfill(' ');
    if (libroPrestado.getDeuda()==1) archReporte<<setw(15)<<"Deuda";
    archReporte<<endl;
    return archReporte;
}

const char *LibroPrestado::getCodigo() const {
    return this->codigoLib;
}

int LibroPrestado::getFecha() const {
    return this->fechaDeRetiro;
}

int LibroPrestado::getDeuda() const {
    return this->deuda;
}

LibroPrestado::~LibroPrestado() {
    delete[] this->codigoLib;
    this->codigoLib=nullptr;
}
