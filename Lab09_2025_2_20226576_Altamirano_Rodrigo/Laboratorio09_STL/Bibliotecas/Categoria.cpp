#include <iomanip>
//
// Created by hrodic on 26/06/2026.
//
using namespace std;
#include "Categoria.h"

std::string Categoria::getCodigo() const {
    return this->codigo;
}

std::string Categoria::getNombre() const {
    return this->nombre;
}

std::string Categoria::getDescripcion() const {
    return this->descripcion;
}

void Categoria::leer(std::ifstream& input) {
    std::string codigo;
    getline(input,codigo,',');
    if (input) {
        this->codigo=codigo;
        getline(input,this->nombre,',');
        getline(input,this->descripcion);
    }
}

void Categoria::imprimir(std::ofstream& output) const {
    output<<setw(3)<<" "<<left<<setw(15)<<"CODIGO:"<<this->codigo<<endl;
    output<<setw(3)<<" "<<setw(15)<<"NOMBRE:"<<this->nombre<<endl;
    output<<setw(3)<<" "<<setw(15)<<"DESCRIPCION:"<<this->descripcion<<endl;
}

void Categoria::setCodigo(const std::string &codigo) {
    this->codigo=codigo;
}

bool Categoria::operator<(const Categoria &categoria) const {
    return this->codigo<categoria.codigo;
}

bool Categoria::operator==(const Categoria &categoria) const {
    return this->codigo==categoria.codigo;
}

std::ifstream& operator>>(std::ifstream& input,Categoria& categoria) {
    categoria.leer(input);
    return input;
}

std::ofstream& operator<<(std::ofstream& output,const Categoria& categoria) {
    categoria.imprimir(output);
    return output;
}