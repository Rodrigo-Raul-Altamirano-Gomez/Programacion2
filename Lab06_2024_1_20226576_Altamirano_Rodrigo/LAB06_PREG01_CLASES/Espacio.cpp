//
// Created by hrodic on 8/05/2026.
//
#include "Espacio.h"

void Espacio::setPosiciones(int posX,int posY) {
    this->posx=posX;
    this->posy=posY;
}

void Espacio::setOcupado(char ocupado) {
    this->contenido=ocupado;
}

char Espacio::getContenido() const {
    return this->contenido;
}

ofstream& operator<<(ofstream& archReporte,const Espacio& espacio) {
    if (espacio.getContenido()=='S') archReporte<<"[ * ]";
    else archReporte<<"[   ]";
    return archReporte;
}
