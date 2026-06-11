//
// Created by hrodic on 3/06/2026.
//
#include <cstring>
#include <iomanip>
#include "Infraccion.h"

Infraccion::Infraccion() {
    this->tipo_infraccion=nullptr;
    this->placa=nullptr;
}

Infraccion::Infraccion(const Infraccion& infraccion) : Infraccion() {
    *this=infraccion;
}

Infraccion& Infraccion::operator=(const Infraccion& infraccion) {
    if (this!=&infraccion) {
        this->fecha_evento=infraccion.fecha_evento;
        this->set_tipo_infraccion(infraccion.tipo_infraccion);
        this->monto=infraccion.monto;
        this->fecha_pago_limite=infraccion.fecha_pago_limite;
        this->set_placa(infraccion.placa);
    }
    return *this;
}

void Infraccion::set_tipo_infraccion(const char *tipo_infraccion) {
    delete[] this->tipo_infraccion;
    this->tipo_infraccion=new char[strlen(tipo_infraccion)+1];
    strcpy(this->tipo_infraccion,tipo_infraccion);
}

void Infraccion::set_placa(const char *placa) {
    delete[] this->placa;
    this->placa=new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}

int Infraccion::get_fecha_evento() const {
    return this->fecha_evento;
}

char* Infraccion::get_tipo_infraccion() const {
    char* tipo_infraccion_copia=new char[strlen(this->tipo_infraccion)+1];
    strcpy(tipo_infraccion_copia,this->tipo_infraccion);
    return tipo_infraccion_copia;
}

double Infraccion::get_monto() const {
    return this->monto;
}

int Infraccion::get_fecha_pago_limite() const {
    return this->fecha_pago_limite;
}

char* Infraccion::get_placa() const {
    char* placa_copia=new char[strlen(this->placa)+1];
    strcpy(placa_copia,this->placa);
    return placa_copia;
}

void Infraccion::completar_infraccion(char tipo, int valor,int valor_referencia) {
    int porcentaje_multa;
    if (tipo=='V') {
        this->set_tipo_infraccion("Velocidad");
        if (valor<valor_referencia) porcentaje_multa=5;
        else porcentaje_multa=8;
    } else if (tipo=='S') {
        this->set_tipo_infraccion("Semaforo");
        if (valor<valor_referencia) porcentaje_multa=5;
        else porcentaje_multa=8;
    } else {
        this->set_tipo_infraccion("Estacionamiento");
        if (valor<valor_referencia) porcentaje_multa=5;
        else porcentaje_multa=8;
    }
    this->monto=((double)porcentaje_multa/100)*5350;
    if ((this->fecha_evento%10000)/100<12) this->fecha_pago_limite=this->fecha_evento+1*100;
    else this->fecha_pago_limite=this->fecha_evento+1*10000-11*100;
}

void Infraccion::leer(ifstream &arch) {
    char placa[20],car;
    int dia_evento,mes_evento,anio_evento;
    arch.getline(placa,20,',');
    arch>>dia_evento>>car>>mes_evento>>car>>anio_evento>>car;
    this->set_placa(placa);
    this->fecha_evento=dia_evento+mes_evento*100+anio_evento*10000;
}

void Infraccion::imprimir(ofstream &arch) const {
    arch<<setw(8)<<this->fecha_evento<<setw(5)<<" "<<left<<setw(15)<<this->tipo_infraccion<<right;
    arch<<setw(7)<<this->monto<<setw(12)<<this->fecha_pago_limite<<setw(5)<<" "<<this->placa<<endl;
}

ifstream& operator>>(ifstream& arch,Infraccion& infraccion) {
    infraccion.leer(arch);
    return arch;
}

ofstream& operator<<(ofstream& arch,const Infraccion& infraccion) {
    infraccion.imprimir(arch);
    return arch;
}

Infraccion::~Infraccion() {
    delete[] this->tipo_infraccion;
    delete[] this->placa;
}
