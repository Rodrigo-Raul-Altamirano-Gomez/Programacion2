//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_REVISTA_H
#define LAB08_POLITAD_REVISTA_H
#include "Libro.h"


class Revista : public Libro {
    int ISSN;
    int anho;
    int numero;
    int vigencia;
public:
    Revista();
    void lee(ifstream &) override;
    void actualiza() override;
    void imprime(ofstream &) const override;
};


#endif //LAB08_POLITAD_REVISTA_H
