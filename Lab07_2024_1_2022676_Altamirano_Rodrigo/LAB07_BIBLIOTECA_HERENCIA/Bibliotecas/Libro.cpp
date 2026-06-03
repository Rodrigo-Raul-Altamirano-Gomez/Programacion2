//
// Created by hrodic on 25/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Libro.h"

Libro::Libro() {
    this->codigo=nullptr;
    this->nombre=nullptr;
    this->colocado=false;
}

Libro::Libro(const Libro &libro) : Libro() {
    *this=libro;
}

void Libro::leerLibro(ifstream &archLibro) {
    char car;
    this->codigo=this->leerCadena(archLibro);
    this->nombre=this->leerCadena(archLibro);
    archLibro>>this->ancho>>car>>this->alto>>car;
}

char *Libro::leerCadena(ifstream &archLibros) const {
    char buffer[100],*cadenaExacta;
    archLibros.getline(buffer,100,',');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

char *Libro::copiarCadena(const char *cadena) const {
    char* nuevaCadena=new char[strlen(cadena)+1];
    strcpy(nuevaCadena,cadena);
    return nuevaCadena;
}

int Libro::getAltura() const {
    return this->alto;
}

int Libro::getAnchura() const {
    return this->ancho;
}

void Libro::setColocado(bool colocado) {
    this->colocado=colocado;
}

void Libro::setPeso(double peso) {
    this->peso=peso;
}

Libro &Libro::operator=(const Libro &libro) {
    if (this!=&libro) {
        delete[] this->codigo;
        this->codigo=this->copiarCadena(libro.codigo);
        delete[] this->nombre;
        this->nombre=this->copiarCadena(libro.nombre);
        this->ancho=libro.ancho;
        this->alto=libro.alto;
        this->colocado=libro.colocado;
        this->peso=libro.peso;
    }
    return *this;
}

void Libro::imprimirLibro(ofstream &archReporte) const {
    archReporte<<left<<setw(10)<<this->codigo;
    if (this->colocado) archReporte<<setw(25)<<this->nombre;
    else archReporte<<setw(25)<<"NO SE PUDO COLOCAR";
    archReporte<<right<<setw(3)<<this->ancho<<setw(7)<<this->alto<<setw(7)<<this->peso<<endl;
}

Libro::~Libro() {
    delete[] this->codigo;
    delete[] this->nombre;
}
