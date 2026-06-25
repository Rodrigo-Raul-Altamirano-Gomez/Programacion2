//
// Created by hrodic on 23/06/2026.
//

#include "NLibro.h"

NLibro::NLibro() {
    this->plibro=nullptr;
}

NLibro::NLibro(const NLibro& nlibro) : NLibro() {
    *this=nlibro;
}

NLibro& NLibro::operator=(const NLibro& nlibro) {
    if (this!=&nlibro) {
        delete this->plibro;
        if (nlibro.plibro) this->plibro=nlibro.plibro->clonar();
        else this->plibro=nullptr;
    }
    return *this;
}

Libro*& NLibro::operator*() {
    return this->plibro;
}

NLibro::~NLibro() {
    delete this->plibro;
}