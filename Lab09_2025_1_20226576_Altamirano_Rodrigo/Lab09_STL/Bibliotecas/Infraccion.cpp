#include <iomanip>
//
// Created by hrodic on 25/06/2026.
//
using namespace std;
#include "Infraccion.h"

Infraccion::Infraccion(const std::string &codigo) {
    this->codigo=codigo;
}

std::string Infraccion::getCodigo() const {
    return this->codigo;
}

double Infraccion::getMulta() const {
    return this->multa;
}

std::string Infraccion::getGravedad() const {
    return this->gravedad;
}

std::string Infraccion::getDescripcion() const {
    return this->descripcion;
}

bool Infraccion::leer(std::ifstream &input) {
    string codigo;
    char car;
    getline(input, codigo, ',');
    if (input) {
        this->codigo = codigo;
        input>>this->multa>>car;
        getline(input, this->gravedad, ',');
        getline(input, this->descripcion);
        return true;
    }
    return false;
}

void Infraccion::imprimir(std::ofstream &output) const {
    output<<left<<setw(7)<<this->codigo<<right<<setw(7)<<this->multa<<setw(5)<<" ";
    output<<left<<setw(12)<<this->descripcion<<this->descripcion<<endl;
}

bool Infraccion::operator<(const Infraccion &infraccion) const {
    return this->codigo<infraccion.codigo;
}

bool Infraccion::operator==(const Infraccion &infraccion) const {
    return this->codigo==infraccion.codigo;
}

std::ifstream& operator>> (std::ifstream& input, Infraccion& infraccion) {
    infraccion.leer(input);
    return input;
}

std::ofstream& operator<< (std::ofstream& output, const Infraccion& infraccion) {
    infraccion.imprimir(output);
    return output;
}