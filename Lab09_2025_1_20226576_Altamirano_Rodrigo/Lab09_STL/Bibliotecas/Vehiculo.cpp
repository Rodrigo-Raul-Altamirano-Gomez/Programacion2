#include <iomanip>
//
// Created by hrodic on 25/06/2026.
//
using namespace std;
#include "Vehiculo.h"

std::string Vehiculo::getPlaca() const {
    return this->placa;
}

std::string Vehiculo::getMarca() const {
    return this->marca;
}

std::string Vehiculo::getModelo() const {
    return this->modelo;
}

void Vehiculo::leer(std::ifstream &input) {
    getline(input, this->placa,',');
    getline(input, this->marca,',');
    getline(input, this->modelo);
}

void Vehiculo::imprimir(std::ofstream& output) const {
    output<<left<<setw(12)<<this->placa<<setw(15)<<this->marca<<this->modelo<<endl;
}

std::ifstream &operator>>(std::ifstream &input, Vehiculo &vehiculo) {
    vehiculo.leer(input);
    return input;
}

std::ofstream& operator<<(std::ofstream &output, const Vehiculo &vehiculo) {
    vehiculo.imprimir(output);
    return output;
}
