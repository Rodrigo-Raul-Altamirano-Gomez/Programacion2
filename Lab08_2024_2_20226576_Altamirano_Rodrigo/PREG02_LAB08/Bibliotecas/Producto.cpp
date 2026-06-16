//
// Created by hrodic on 14/06/2026.
//

#include "Producto.h"

#include <cstring>
#include <iomanip>

Producto::Producto() {
    this->nombre=nullptr;
}

Producto::Producto(const Producto &producto) : Producto() {
    *this=producto;
}

Producto &Producto::operator=(const Producto &producto) {
    if (this!=&producto) {
        this->setNombre(producto.nombre);
        this->precio=producto.precio;
    }
    return *this;
}

void Producto::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Producto::leer(ifstream &archComandas) {
    char car,nombre[30];
    archComandas.getline(nombre,30,',');
    this->setNombre(nombre);
    archComandas>>this->precio>>car;
}

void Producto::imprimir(ofstream &archReporte) const {
    archReporte<<setw(10)<<" "<<"Nombre: "<<this->nombre<<endl;
    archReporte<<setw(10)<<" "<<"Precio: "<<this->precio<<endl;
}

Producto::~Producto() {
    delete[] this->nombre;
}
