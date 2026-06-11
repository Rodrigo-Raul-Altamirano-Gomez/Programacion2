//
// Created by hrodic on 4/06/2026.
//
#include <iomanip>
#include "Comanda.h"

Comanda::Comanda() {
    this->cantidad_bebidas=0;
    this->cantidad_entradas=0;
    this->cantidad_platos_fondo=0;
    this->total=0;
    this->estado=nullptr;
}

void Comanda::set_id(int id) {
    this->id=id;
}

int Comanda::get_id() const {
    return this->id;
}

void Comanda::completar(int hora_atencion, int hora_servicio) {
    this->hora_atencion=hora_atencion;
    this->hora_servicio=hora_servicio;
    this->tiempo_preparacion=this->cantidad_bebidas*10+this->cantidad_entradas*15+this->cantidad_platos_fondo*20;
}

void Comanda::leer(ifstream &archComandas) {
    char tipoProducto,car;
    archComandas>>tipoProducto>>car;
    if (tipoProducto=='B') {
        archComandas >> this->bebidas[this->cantidad_bebidas];
        this->cantidad_bebidas++;
    } else if (tipoProducto=='E') {
        archComandas >> this->entradas[this->cantidad_entradas];
        this->cantidad_entradas++;
    } else {
        archComandas >> this->platos_fondo[this->cantidad_platos_fondo];
        this->cantidad_platos_fondo++;
    }
}

void Comanda::imprimir(ofstream &archReporte) const {
    archReporte<<"ID: "<<setw(2)<<this->id<<" Hora Atencion: "<<setw(4)<<this->hora_atencion<<" Hora Servicio: ";
    archReporte<<setw(4)<<this->hora_servicio<<" Tiempo Preparacion: "<<setw(4)<<this->tiempo_preparacion;
    archReporte<<" Total: "<<setw(5)<<this->total<<" Estado: ";
    this->estado ? archReporte<<this->estado<<endl:archReporte<<endl;
    archReporte<<"Cantidad Bebidas: "<<this->cantidad_bebidas<<endl;
    for (int i=0;i<this->cantidad_bebidas;i++) archReporte<<this->bebidas[i]<<endl;
    archReporte<<"Cantidad Entradas: "<<this->cantidad_entradas<<endl;
    for (int i=0;i<this->cantidad_entradas;i++) archReporte<<this->entradas[i]<<endl;
    archReporte<<"Cantidad Platos de Fondo: "<<this->cantidad_platos_fondo<<endl;
    for (int i=0;i<this->cantidad_platos_fondo;i++) archReporte<<this->platos_fondo[i]<<endl;
}

ifstream& operator>>(ifstream& archComandas,Comanda& comanda) {
    comanda.leer(archComandas);
    return archComandas;
}

ofstream& operator<<(ofstream& archReporte,const Comanda& comanda) {
    archReporte<<fixed<<setprecision(2);
    comanda.imprimir(archReporte);
    return archReporte;
}

Comanda::~Comanda() {
    delete[] this->estado;
}
