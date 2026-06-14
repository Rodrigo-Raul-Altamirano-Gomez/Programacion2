//
// Created by hrodic on 12/06/2026.
//
#include <iomanip>
#include "NPedido.h"

#include <cstring>

NPedido::NPedido() {
    this->codigo=nullptr;
    this->sig=nullptr;
}

void NPedido::setCodigo(const char *codigo) {
    delete[] this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void NPedido::imprimir(ofstream &archReporte) const {
    archReporte<<setw(23)<<" "<<left<<setw(10)<<this->codigo<<right<<setw(2)<<this->cantidad;
    archReporte<<setw(10)<<this->peso<<endl;
}

NPedido::~NPedido() {
    delete[] this->codigo;
    delete this->sig;
}
