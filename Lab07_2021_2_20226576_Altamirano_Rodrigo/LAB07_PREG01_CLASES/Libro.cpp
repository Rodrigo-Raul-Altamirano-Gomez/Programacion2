//
// Created by hrodic on 10/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Libro.h"

Libro::Libro() {
    this->codigo=nullptr;
    this->titulo=nullptr;
    this->autor=nullptr;
    this->prestados=0;
    this->cantEst=0;
    this->cantDoc=0;
    this->cantAdm=0;
}

ifstream& operator>>(ifstream& archLibros,Libro& libro) {
    char codigo[20],titulo[200],autor[100],car;
    archLibros.getline(codigo,20,',');
    if (archLibros) {
        int stock;
        double precio;
        archLibros.getline(titulo,200,',');
        archLibros.getline(autor,100,',');
        archLibros.ignore(20,',');
        archLibros>>stock>>car>>precio;
        archLibros.ignore();
        libro.setCodigo(codigo);
        libro.setTitulo(titulo);
        libro.setAutor(autor);
        libro.setStock(stock);
        libro.setPrecio(precio);
    }
    return archLibros;
}

void Libro::setCodigo(const char *codigo) {
    delete[] this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Libro::setTitulo(const char *titulo) {
    delete[] this->titulo;
    this->titulo=new char[strlen(titulo)+1];
    strcpy(this->titulo,titulo);
}

void Libro::setAutor(const char *autor) {
    delete[] this->autor;
    this->autor=new char[strlen(autor)+1];
    strcpy(this->autor,autor);
}

void Libro::setStock(int stock) {
    this->stock=stock;
}

void Libro::setPrecio(double precio) {
    this->precio=precio;
}

Libro &Libro::operator+=(const LibroPrestado &libroPrestado) {
    this->prestados++;
    if (libroPrestado.getTipo()=='E') this->cantEst++;
    else if (libroPrestado.getTipo()=='D') this->cantDoc++;
    else this->cantAdm++;
    return *this;
}

ofstream& operator<<(ofstream& archReporte,const Libro& libro) {
    archReporte<<"Cdoigo: "<<libro.getCodigo()<<endl;
    archReporte<<"Titulo: "<<libro.getTitulo()<<endl;
    archReporte<<"Autor: "<<libro.getAutor()<<endl;
    archReporte<<"Stock: "<<libro.getStock()<<endl;
    archReporte<<setfill('=')<<setw(75)<<" "<<setfill(' ')<<endl;
    archReporte<<left<<setw(28)<<"Prestamo a docentes:"<<libro.getNumDoc()<<endl;
    archReporte<<setw(28)<<"Prestamo a alumnos:"<<libro.getNumEst()<<endl;
    archReporte<<"Prestamo a administrativos: "<<libro.getNumAdm()<<endl;
    archReporte<<setfill('-')<<setw(75)<<" "<<setfill(' ')<<endl;
    archReporte<<setw(28)<<"Total de Prestamos:"<<libro.getNumPrestamos()<<endl;
    archReporte<<setfill('=')<<setw(75)<<" "<<setfill(' ')<<endl;
    return archReporte;
}

const char *Libro::getCodigo() const {
    return this->codigo;
}

const char *Libro::getTitulo() const {
    return this->titulo;
}

const char *Libro::getAutor() const {
    return this->autor;
}

int Libro::getStock() const {
    return this->stock;
}

int Libro::getNumEst() const {
    return this->cantEst;
}

int Libro::getNumDoc() const {
    return this->cantDoc;
}

int Libro::getNumAdm() const {
    return this->cantAdm;
}

int Libro::getNumPrestamos() const {
    return this->prestados;
}

Libro::~Libro() {
    delete[] this->codigo;
    delete[] this->titulo;
    delete[] this->autor;
    this->codigo=nullptr;
    this->titulo=nullptr;
    this->autor=nullptr;
}
