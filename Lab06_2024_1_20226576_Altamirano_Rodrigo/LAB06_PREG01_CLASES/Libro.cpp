//
// Created by hrodic on 8/05/2026.
//
#include <cstring>
#include <fstream>
#include "Libro.h"
using namespace std;

void Libro::setDatosLibro(const char * codigo,const char * nombre,int ancho,int alto) {
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
    this->ancho=ancho;
    this->alto=alto;
}

void Libro::setEstado(bool estado) {
    this->colocado=estado;
}

ifstream& operator>>(ifstream& archLibros,Libro& libro) {
    char buffer1[200],buffer2[200],car;
    archLibros.getline(buffer1,200,',');
    if (archLibros) {
        int alto,ancho;
        archLibros.getline(buffer2,200,',');
        archLibros>>ancho>>car>>alto;
        archLibros.ignore();
        libro.setDatosLibro(buffer1,buffer2,ancho,alto);
        libro.setEstado(false);
    }
    return archLibros;
}

int Libro::getAncho() const{
    return this->ancho;
}

int Libro::getAlto() const{
    return this->alto;
}
