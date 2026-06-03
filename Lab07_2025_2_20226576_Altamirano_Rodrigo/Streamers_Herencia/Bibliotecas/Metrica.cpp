//
// Created by hrodic on 1/06/2026.
//
#include <cstring>
#include <iomanip>
#include "Metrica.h"

Metrica::Metrica() {
    this->descripcion=nullptr;
}

Metrica::Metrica(const Metrica &metrica) : Metrica() {
    *this=metrica;
}

Metrica &Metrica::operator=(const Metrica &metrica) {
    if (this!=&metrica) {
        this->id=metrica.id,
        this->setDescripcion(metrica.descripcion);
        this->fecha_calculo=metrica.fecha_calculo;
        this->fecha_expiracion=metrica.fecha_expiracion;
        this->estado=metrica.estado;
    }
    return *this;
}

void Metrica::setDescripcion(const char *descripcion) {
    delete[] this->descripcion;
    this->descripcion=new char[strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
}

char *Metrica::getDescripcion() const {
    char* descripcion_copia=new char[strlen(this->descripcion)+1];
    strcpy(descripcion_copia,this->descripcion);
    return descripcion_copia;
}

bool Metrica::getEstado() const {
    return this->estado;
}

void Metrica::leer(ifstream &archMetricas) {
    char car,descripcion[100];
    int diaCalculo,mesCalculo,anioCalculo,diaExpiracion,mesExpiracion,anioExpiracion;
    archMetricas>>this->id>>car;
    archMetricas.getline(descripcion,100,',');
    archMetricas>>anioCalculo>>car>>mesCalculo>>car>>diaCalculo>>car>>anioExpiracion>>car>>mesExpiracion;
    archMetricas>>car>>diaExpiracion>>car;
    this->setDescripcion(descripcion);
    this->fecha_calculo=diaCalculo+mesCalculo*100+anioCalculo*10000;
    this->fecha_expiracion=diaExpiracion+mesExpiracion*100+anioExpiracion*10000;
    20251107>this->fecha_expiracion ? this->estado=false:this->estado=true;
}

void Metrica::imprimir(ofstream &archReporte) const {
    archReporte<<right<<setw(7)<<this->id<<setw(18)<<this->fecha_calculo<<setw(12)<<this->fecha_expiracion;
    archReporte<<setw(4)<<" "<<left;
    this->estado ? archReporte<<setw(10)<<"ACTIVA":archReporte<<setw(10)<<"EXPIRADA";
}

Metrica::~Metrica() {
    delete[] this->descripcion;
}



