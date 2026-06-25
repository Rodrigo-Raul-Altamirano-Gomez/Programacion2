//
// Created by hrodic on 23/06/2026.
//
using namespace std;
#include <fstream>
#include "Palabra.h"

Palabra::Palabra(std::string texto, int polaridad) {
    this->texto=texto;
    this->polaridad=polaridad;
}

std::string Palabra::getTexto() const {
    return this->texto;
}
