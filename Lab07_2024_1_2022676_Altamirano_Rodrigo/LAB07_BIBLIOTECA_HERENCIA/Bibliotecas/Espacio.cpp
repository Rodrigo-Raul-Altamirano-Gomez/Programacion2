//
// Created by hrodic on 25/05/2026.
//

#include "Espacio.h"

Espacio::Espacio() {
    this->contenido='N';
}

char Espacio::getContenido() const {
    return this->contenido;
}

void Espacio::setContenido(char contenido) {
    this->contenido=contenido;
}

void Espacio::setPosX(int posX) {
    this->posx=posX;
}

void Espacio::setPosY(int posY) {
    this->posy=posY;
}
