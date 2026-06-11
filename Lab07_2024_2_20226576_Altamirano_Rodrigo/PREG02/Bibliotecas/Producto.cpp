//
// Created by hrodic on 4/06/2026.
//
#include <cstring>
#include <iomanip>
#include "Producto.h"

Producto::Producto() {
    this->nombre=nullptr;
}

Producto::Producto(const Producto& producto) :  Producto() {
    *this=producto;
}

Producto& Producto::operator=(const Producto& producto) {
    if (this!=&producto) {
        this->set_nombre(producto.nombre);
        this->precio=producto.precio;
    }
    return *this;
}

void Producto::set_nombre(const char* nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

double Producto::get_precio() const {
    return this->precio;
}

void Producto::leer(ifstream &archComandas) {
    char nombre[50],car;
    archComandas.getline(nombre,50,',');
    archComandas>>this->precio>>car;
    this->set_nombre(nombre);
}

void Producto::imprimir(ofstream &archReporte) const {
    archReporte<<left<<"Nombre: "<<setw(20)<<this->nombre<<right<<"Precio: "<<setw(4)<<this->precio;
}

Producto::~Producto() {
    delete[] this->nombre;
}
