//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_ESTANTEHORIZONTAL_H
#define LAB07_BIBLIOTECA_HERENCIA_ESTANTEHORIZONTAL_H

#include "Estante.h"
#include "Novela.h"

class EstanteHorizontal : Estante {
    Novela novelas[5];
    int cantidad_novelas;
public:
    EstanteHorizontal();
    void leerEstanteHorizontal(ifstream&);
    int getAnchuraSobrante() const;
    int getAltura() const;
    double getPesoMaximo() const;
    double getPesoActual() const;
    void insertarNovela(const Novela&);
    void escribirEstanteHorizontal(ofstream&) const;
};

ifstream& operator>>(ifstream&,EstanteHorizontal&);
ofstream& operator<<(ofstream&,const EstanteHorizontal&);

#endif //LAB07_BIBLIOTECA_HERENCIA_ESTANTEHORIZONTAL_H
