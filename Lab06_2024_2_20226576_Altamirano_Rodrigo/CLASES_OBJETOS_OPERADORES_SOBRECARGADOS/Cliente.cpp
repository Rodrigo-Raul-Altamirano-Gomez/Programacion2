//
// Created by hrodic on 14/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Cliente.h"

Cliente::Cliente() {
    this->nombre=nullptr;
    this->distrito=nullptr;
    this->totalPagado=0;
}

Cliente::Cliente(const Cliente& cliente) : Cliente() {
    *this=cliente;
}

int Cliente::getDni() const {
    return this->dni;
}

const char* Cliente::getNombre() const {
    return this->nombre;
}

const char* Cliente::getDistrito() const {
    return this->distrito;
}

double Cliente::getDescuento() const {
    return this->descuento;
}

double Cliente::getTotalPagado() const {
    return this->totalPagado;
}

Cliente& Cliente::operator=(const Cliente& cliente) {
    if (this!=&cliente) {
        this->dni=cliente.dni;
        setNombre(cliente.nombre);
        setDistrito(cliente.distrito);
        this->descuento=cliente.descuento;
        this->totalPagado=cliente.totalPagado;
    }
    return *this;
}

void Cliente::setDni(int dni) {
    this->dni=dni;
}

void Cliente::setNombre(const char *nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Cliente::setDistrito(const char *distrito) {
    delete[] this->distrito;
    this->distrito=new char[strlen(distrito)+1];
    strcpy(this->distrito,distrito);
}

void Cliente::setDescuento(double descuento) {
    this->descuento=descuento;
}

ifstream& operator>>(ifstream& archClientes,Cliente& cliente) {
    int dni;
    if (archClientes>>dni) {
        char nombre[100],distrito[100],tieneDescuento,car;
        double descuento=0;
        archClientes.ignore();
        archClientes.getline(nombre,100,',');
        archClientes.getline(distrito,100,',');
        archClientes>>tieneDescuento;
        if (tieneDescuento=='S') archClientes>>car>>descuento>>car;
        cliente.setDni(dni);
        cliente.setNombre(nombre);
        cliente.setDistrito(distrito);
        cliente.setDescuento(descuento);
    }
    return archClientes;
}

void Cliente::incrementarTotal(double pagoCliente) {
    this->totalPagado+=pagoCliente;
}

ofstream& operator<<(ofstream& archReporte,const Cliente& cliente) {
    archReporte<<setfill('0')<<setw(8)<<cliente.getDni()<<setfill(' ')<<setw(3)<<" "<<left;
    archReporte<<setw(45)<<cliente.getNombre()<<setw(30)<<cliente.getDistrito()<<right;
    archReporte<<setw(5)<<cliente.getDescuento()<<"%"<<setw(8)<<cliente.getTotalPagado()<<endl;
    return archReporte;
}

Cliente::~Cliente() {
    delete[] this->nombre;
    delete[] this->distrito;
    this->nombre=nullptr;
    this->distrito=nullptr;
}
