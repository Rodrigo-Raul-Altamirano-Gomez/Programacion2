//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ENCICLOPEDIA_H
#define LAB07_BIBLIOTECA_HERENCIA_ENCICLOPEDIA_H

#include "Libro.h"

class Enciclopedia : Libro {
    int volumen;
    double peso;
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia&);
    void leerEnciclopedia(ifstream&);
    int getAltura() const;
    int getAnchura() const;
    double getPeso() const;
    void setColocado(bool);
    Enciclopedia& operator=(const Enciclopedia&);
    void imprimirEnciclopedia(ofstream&) const;
};

ifstream& operator>>(ifstream&,Enciclopedia&);
ofstream& operator<<(ofstream&,const Enciclopedia&);

#endif //LAB07_BIBLIOTECA_HERENCIA_ENCICLOPEDIA_H
