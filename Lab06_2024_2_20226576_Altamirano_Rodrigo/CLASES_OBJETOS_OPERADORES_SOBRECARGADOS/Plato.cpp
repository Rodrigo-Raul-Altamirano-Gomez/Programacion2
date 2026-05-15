//
// Created by hrodic on 14/05/2026.
//
#include <cstring>
#include <iomanip>
#include "Plato.h"

Plato::Plato() {
    this->codigo=nullptr;
    this->nombre=nullptr;
    this->categoria=nullptr;
    this->atendidos=0;
    this->noAtendidos=0;
    this->totalEsperado=0;
    this->totalBruto=0;
    this->totalNeto=0;
}

Plato::Plato(const Plato& plato) : Plato() {
    *this=plato;
}

const char* Plato::getCodigo() const {
    return this->codigo;
}

const char* Plato::getNombre() const {
    return this->nombre;
}

double Plato::getPrecio() const {
    return this->precio;
}

const char* Plato::getCategoria() const {
    return this->categoria;
}

int Plato::getPreparados() const {
    return this->preparados;
}

double Plato::getDescuento() const {
    return this->descuento;
}

int Plato::getAtendidos() const {
    return this->atendidos;
}

int Plato::getNoAtendidos() const {
    return this->noAtendidos;
}

double Plato::getTotalEsperado() const {
    return this->totalEsperado;
}

double Plato::getTotalBruto() const {
    return this->totalBruto;
}

double Plato::getTotalNeto() const {
    return this->totalNeto;
}

Plato& Plato::operator=(const Plato& plato) {
    if (this!=&plato) {
        setCodigo(plato.codigo);
        setNombre(plato.nombre);
        this->precio=plato.precio;
        setCategoria(plato.categoria);
        this->preparados=plato.preparados;
        this->descuento=plato.descuento;
        this->atendidos=plato.atendidos;
        this->noAtendidos=plato.noAtendidos;
        this->totalEsperado=plato.totalEsperado;
        this->totalBruto=plato.totalBruto;
        this->totalNeto=plato.totalNeto;
    }
    return *this;
}

void Plato::setCodigo(const char* codigo) {
    delete[] this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Plato::setNombre(const char* nombre) {
    delete[] this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Plato::setPrecio(double precio) {
    this->precio=precio;;
}

void Plato::setCategoria(const char* categoria) {
    delete[] this->categoria;
    this->categoria=new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}

void Plato::setPreparados(int preparados) {
    this->preparados=preparados;
}

void Plato::setDescuento(double descuento) {
    this->descuento=descuento;
}

ifstream& operator>>(ifstream& archPlatos,Plato& plato) {
    char codigo[20],nombre[100],categoria[30],car;
    archPlatos.getline(codigo,20,',');
    if (archPlatos) {
        double precio,descuento=0;
        int preparados;
        archPlatos.getline(nombre,100,',');
        archPlatos>>precio>>car;
        archPlatos.getline(categoria,30,',');
        archPlatos>>preparados;
        if (archPlatos.peek()!='\n') archPlatos>>car>>descuento>>car;
        archPlatos.ignore();
        plato.setCodigo(codigo);
        plato.setNombre(nombre);
        plato.setPrecio(precio);
        plato.setCategoria(categoria);
        plato.setPreparados(preparados);
        plato.setDescuento(descuento);
    }
    return archPlatos;
}

void Plato::incrementarAntendidos(int cantPlatoPedido) {
    this->atendidos+=cantPlatoPedido;
}

void Plato::setTotalEsperado(double totalEsperado) {
    this->totalEsperado=totalEsperado;
}

void Plato::incrementarTotalBruto(double pagoPlatoBruto) {
    this->totalBruto+=pagoPlatoBruto;
}

void Plato::incrementarTotalNeto(double pagoPlatoNeto) {
    this->totalNeto+=pagoPlatoNeto;
}

void Plato::incrementarNoAntendidos(int cantPlatoPedido) {
    this->noAtendidos+=cantPlatoPedido;
}

ofstream& operator<<(ofstream& archReporte,const Plato& plato) {
    archReporte<<left<<setw(12)<<plato.getCodigo()<<setw(45)<<plato.getNombre()<<right;
    archReporte<<setw(6)<<plato.getPrecio()<<setw(4)<<" "<<left<<setw(15)<<plato.getCategoria()<<right;
    archReporte<<setw(7)<<plato.getPreparados()<<setw(15)<<plato.getDescuento()<<"%";
    archReporte<<setw(13)<<plato.getAtendidos()<<setw(15)<<plato.getNoAtendidos();
    archReporte<<setw(17)<<plato.getTotalEsperado()<<setw(12)<<plato.getTotalBruto();
    archReporte<<setw(11)<<plato.getTotalNeto()<<endl;
    return archReporte;
}

Plato::~Plato() {
    delete[] this->codigo;
    delete[] this->nombre;
    delete[] this->categoria;
    this->codigo=nullptr;
    this->nombre=nullptr;
    this->categoria=nullptr;
}
