//
// Created by hrodic on 8/05/2026.
//

#include "Espacio.h"

void Espacio::setPosiciones(int posX,int posY) {
    this->posx=posX;
    this->posy=posY;
}

void Espacio::setOcupado(bool ocupado) {
    this->contenido=ocupado;
}

bool Espacio::getContenido() {
    return this->contenido;
}
