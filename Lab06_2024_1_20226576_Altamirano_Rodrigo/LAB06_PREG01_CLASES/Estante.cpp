//
// Created by hrodic on 8/05/2026.
//
#include <cstring>
#include <fstream>
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
        espacio.setOcupado(false);
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
    else return false;
}

int Estante::getEspaciosSobrantes() {
    for (int i=0;i<this->anchura;i++) {
        if (not this->espacios[i].getContenido()) return i;
    }
    return -1;
}

void Estante::actualizarEspacios(int posXIni,const Libro& libro) {
    for (int i=0;i<this->anchura*this->altura;i++) {
        int posX=i%this->anchura;
        int posY=i/this->anchura;
        if (posX>=posXIni and posX<posXIni+libro.getAncho() and posY<libro.getAlto()) {
            this->espacios[i].setOcupado(true);
        }
    }
}
