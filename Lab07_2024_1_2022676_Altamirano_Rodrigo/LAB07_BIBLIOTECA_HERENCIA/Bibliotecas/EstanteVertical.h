//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESTANTEVERTICAL_H
#define LAB07_BIBLIOTECA_HERENCIA_ESTANTEVERTICAL_H

#include "Estante.h"
#include "Enciclopedia.h"

#include "Enciclopedia.h"

class EstanteVertical : Estante {
    Enciclopedia enciclopedias[5];
    int cantidad_enciclopedias;
public:
    EstanteVertical();
    void leerEstanteVertical(ifstream&);
    int getAlturaSobrante() const;
    int getAnchura() const;
    double getPesoMaximo() const;
    double getPesoActual() const;
    void insertarEnciclopedia(const Enciclopedia&);
    void imprimirEstanteVertical(ofstream&) const;
};

ifstream& operator>>(ifstream&,EstanteVertical&);
ofstream& operator<<(ofstream&,const EstanteVertical&);

#endif //LAB07_BIBLIOTECA_HERENCIA_ESTANTEVERTICAL_H
