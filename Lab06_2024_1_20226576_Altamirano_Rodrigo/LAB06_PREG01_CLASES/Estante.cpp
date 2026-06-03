//
// Created by hrodic on 8/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Estante.h"
using namespace std;

void Estante::setDatosEstante(const char* codigo,int altura,int anchura) {
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
    this->altura=altura;
    this->anchura=anchura;
}

void Estante::setCantidadLibros(int cantidad) {
    this->cantidad_libros=cantidad;
}

ifstream& operator>>(ifstream& archEstantes,Estante& estante) {
    char buffer[200],car;
    archEstantes.getline(buffer,200,',');
    if (archEstantes) {
        int altura,anchura;
        archEstantes>>altura>>car>>anchura;
        archEstantes.ignore();
        estante.setDatosEstante(buffer,altura,anchura);
        estante.setCantidadLibros(0);
        estante.inicializarEspacios();
    }
    return archEstantes;
}

void Estante::inicializarEspacios() {
    this->espacios=new Espacio[this->anchura*this->altura];
    for (int i=0;i<this->anchura*this->altura;i++) {
        Espacio espacio;
        espacio.setPosiciones(i%this->anchura,i/this->anchura);
        espacio.setOcupado('N');
        this->espacios[i]=espacio;
    }
}

bool Estante::operator+=(Libro& libro) {
    int posXVaciaIni=this->getEspaciosSobrantes();
    if (posXVaciaIni>=0) {
        if (this->anchura-posXVaciaIni>=libro.getAncho() and this->altura>=libro.getAlto()) {
            this->libros[this->cantidad_libros]=libro;
            this->cantidad_libros++;
            libro.setEstado(true);
            this->actualizarEspacios(posXVaciaIni,libro);
            return true;
        }
    }
    return false;
}

int Estante::getEspaciosSobrantes() const {
    for (int i=0;i<this->anchura;i++) {
        if (this->espacios[i].getContenido()=='N') return i;
    }
    return -1;
}

void Estante::actualizarEspacios(int posXIni,const Libro& libro) {
    for (int i=0;i<this->anchura*this->altura;i++) {
        int posX=i%this->anchura;
        int posY=i/this->anchura;
        if (posX>=posXIni and posX<posXIni+libro.getAncho() and posY<libro.getAlto()) {
            this->espacios[i].setOcupado('S');
        }
    }
}

const char *Estante::getCodigo() const {
    return this->codigo;
}

int Estante::getCantLibros() const {
    return this->cantidad_libros;
}

int Estante::getAnchura() const {
    return this->anchura;
}

int Estante::getAltura() const {
    return this->altura;
}

void Estante::imprimirEspacios(ofstream& archReporte) const {
    int j=this->altura-1;
    for (int i=this->anchura*j;i>=0;i++) {
        archReporte<<this->espacios[i]<<" ";
        if ((i+1)%this->anchura==0) {
            j--;
            i=j*this->anchura-1;
            archReporte<<endl;
        }
    }
}

void Estante::imprimirLibros(ofstream& archReporte) const {
    for (int i=0;i<this->cantidad_libros;i++) archReporte<<this->libros[i]<<endl;
}

ofstream& operator<<(ofstream& archReporte,const Estante& estante) {
    archReporte<<"Codigo Estante: "<<estante.getCodigo()<<setw(5)<<" ";
    archReporte<<"Cantidad de Libros: "<<estante.getCantLibros()<<endl;
    archReporte<<"Anchura del Estante: "<<estante.getAnchura()<<setw(3)<<" ";
    archReporte<<"Altura del Estante: "<<estante.getAltura()<<endl;
    archReporte<<setfill('-')<<setw(100)<<" "<<setfill(' ')<<endl<<endl;
    estante.imprimirEspacios(archReporte);
    archReporte<<left<<setw(10)<<"CODIGO"<<setw(25)<<"NOMBRE"<<setw(10)<<"ANCHO"<<"ALTO"<<endl;
    archReporte<<setfill('.')<<setw(100)<<" "<<setfill(' ')<<endl;
    estante.imprimirLibros(archReporte);
    return archReporte;
}