//
// Created by hrodic on 25/05/2026.
//

#ifndef LAB07_BIBLIOTECA_HERENCIA_NOVELA_H
#define LAB07_BIBLIOTECA_HERENCIA_NOVELA_H

#include "Libro.h"

class Novela : Libro {
    char* tipo;
    double peso;
public:
    Novela();
    Novela(const Novela&);
    void leerNovela(ifstream&);
    void setColocado(bool);
    int getAnchura() const;
    int getAltura() const;
    double getPeso() const;
    Novela& operator=(const Novela&);
    void imprimirNovela(ofstream&) const;
    ~Novela();
};

ifstream& operator>>(ifstream&,Novela&);
ofstream& operator<<(ofstream&,const Novela&);

#endif //LAB07_BIBLIOTECA_HERENCIA_NOVELA_H
