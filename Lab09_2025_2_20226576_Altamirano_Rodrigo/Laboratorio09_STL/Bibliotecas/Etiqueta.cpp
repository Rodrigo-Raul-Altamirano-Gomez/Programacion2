#include <iomanip>
//
// Created by hrodic on 26/06/2026.
//
using namespace std;
#include "Etiqueta.h"

std::string Etiqueta::getCodigo() const {
    return this->codigo;
}

std::string Etiqueta::getNombre() const {
    return this->nombre;
}

void Etiqueta::leer(std::ifstream& input) {
    std::string codigo;
    getline(input,codigo,',');
    if (input) {
        this->codigo=codigo;
        getline(input,this->nombre);
    }
}

void Etiqueta::imprimir(std::ofstream& output) const {
    output<<left<<"CODIGO: "<<setw(10)<<this->codigo<<"NOMBRE: "<<this->nombre<<endl;
}

std::ifstream& operator>>(std::ifstream& input,Etiqueta& etiqueta) {
    etiqueta.leer(input);
    return input;
}

std::ofstream& operator<<(std::ofstream& output,const Etiqueta& etiqueta) {
    etiqueta.imprimir(output);
    return output;
}