//
// Created by hrodic on 9/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Conductor.h"

Conductor::Conductor() {
    this->lfaltas=nullptr;
    this->numFaltas=0;
    this->montoTotal=0;
    this->nombre=nullptr;
}

ifstream& operator>>(ifstream& archConductores,Conductor& conductor) {
    int licencia;
    if (archConductores>>licencia) {
        char nombre[200];
        archConductores.ignore();
        archConductores.getline(nombre,200,'\n');
        conductor.setLicencia(licencia);
        conductor.setNombre(nombre);
    }
    return archConductores;
}

void Conductor::setLicencia(int licencia) {
    this->licencia=licencia;
}

void Conductor::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

Conductor &Conductor::operator+(const Falta &falta) {
    if (not this->lfaltas) {
        this->lfaltas=new FaltaCond[1]{};
        this->lfaltas[0]=falta;
    }
    else {
        FaltaCond* aux=new FaltaCond[this->numFaltas+1]{};
        for (int i=0;i<this->numFaltas;i++) aux[i]=this->lfaltas[i];
        aux[this->numFaltas]=falta;
        delete[] this->lfaltas;
        this->lfaltas=aux;
    }
    this->numFaltas++;
    return *this;
}

Conductor &Conductor::operator+(const Infraccion &infraccion) {
    for (int i=0;i<this->numFaltas;i++) {
        if (this->lfaltas[i].getCodigo()==infraccion.getCodigo()) {
            this->lfaltas[i].setGravedad(infraccion.getGravedad());
            this->lfaltas[i].setMulta(infraccion.getMulta());
        }
    }
    return *this;
}

Conductor &Conductor::operator++(int) {
    for (int i=0;i<this->numFaltas;i++) {
        this->montoTotal+=this->lfaltas[i].getMulta();
    }
    return *this;
}

Conductor &Conductor::operator*(int fecha) {
    for (int i=0;i<this->numFaltas;i++) {
        FaltaCond& faltaConductor=this->lfaltas[i];
        if (faltaConductor.getFecha()<fecha) {
            const char* gravedad=faltaConductor.getGravedad();
            double multaFalta=faltaConductor.getMulta();
            if (strcmp(gravedad,"Grave")==0) faltaConductor.setMulta(0.75*multaFalta);
            else if (strcmp(gravedad,"Leve")==0) faltaConductor.setMulta(0.5*multaFalta);
            else faltaConductor.setMulta(0.9*multaFalta);
        }
    }
    return *this;
}

ofstream& operator<<(ofstream& archReporte,const Conductor& conductor) {
    archReporte<<fixed<<setprecision(2);
    archReporte<<left<<setw(12)<<"Conductor"<<": "<<conductor.getNombre()<<endl;
    archReporte<<"Licencia No.: "<<conductor.getLicencia()<<endl;
    archReporte<<setfill('=')<<setw(70)<<" "<<setfill(' ')<<endl;
    archReporte<<"Infracciones cometidas:"<<endl;
    archReporte<<setfill('-')<<setw(70)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(5)<<"No."<<setw(12)<<"Fecha"<<setw(10)<<"Placa"<<setw(15)<<"Infraccion";
    archReporte<<setw(12)<<"Gravedad"<<"Multa"<<right<<endl;
    conductor.imprimirFaltas(archReporte);
    archReporte<<setfill('=')<<setw(70)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(40)<<"Cantidad"<<setw(15)<<"Total"<<endl;
    archReporte<<"Total de Infracciones:"<<setw(15)<<conductor.getNumFaltas();
    archReporte<<setw(18)<<conductor.getTotal()<<endl;
    return archReporte;
}

const char *Conductor::getNombre() const {
    return this->nombre;
}

int Conductor::getLicencia() const {
    return this->licencia;
}

void Conductor::imprimirFaltas(ofstream &archReporte) const {
    for (int i=0;i<this->numFaltas;i++) {
        const FaltaCond& faltaConductor=this->lfaltas[i];
        int dia,mes,anio,res,fecha=faltaConductor.getFecha();
        anio=fecha/10000,res=fecha%10000,mes=res/100,dia=res%100;
        archReporte<<i+1<<")"<<setw(3)<<" "<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'<<anio;
        archReporte<<setfill(' ')<<setw(2)<<" "<<left<<setw(12)<<faltaConductor.getPlaca()<<right;
        archReporte<<setw(5)<<faltaConductor.getCodigo()<<setw(8)<<" "<<left;
        archReporte<<setw(12)<<faltaConductor.getGravedad()<<right<<setw(7)<<faltaConductor.getMulta()<<endl;
    }
}

int Conductor::getNumFaltas() const {
    return this->numFaltas;
}


double Conductor::getTotal() const {
    return this->montoTotal;
}

Conductor::~Conductor() {
    delete[] this->lfaltas;
    delete[] this->nombre;
    this->lfaltas=nullptr;
    this->nombre=nullptr;
}
