#include <iomanip>
//
// Created by hrodic on 22/06/2026.
//
using namespace std;
#include "NPedido.h"

NPedido::NPedido() {
    this->cantidad=0;
    this->peso=0;
}

double NPedido::getPeso() const {
    return this->peso;
}

void NPedido::leer(std::ifstream &archPedidos) {
    char car;
    getline(archPedidos,this->codigo,',');
    archPedidos>>this->cantidad>>car>>this->peso;
}

void NPedido::imprimir(std::ofstream &archReporte) const {
    archReporte<<left<<setw(10)<<this->codigo<<right<<setw(2)<<this->cantidad<<setw(7)<<this->peso;
}
