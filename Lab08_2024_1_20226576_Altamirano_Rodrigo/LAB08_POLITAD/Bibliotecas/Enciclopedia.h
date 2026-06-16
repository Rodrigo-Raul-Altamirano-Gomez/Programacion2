//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_ENCICLOPEDIA_H
#define LAB08_POLITAD_ENCICLOPEDIA_H
#include "Libro.h"


class Enciclopedia : public Libro {
    int sku;
    int anho;
    int vigencia;
public:
    Enciclopedia();
    void lee(ifstream &) override;
    void actualiza() override;
    void imprime(ofstream &) const override;
};


#endif //LAB08_POLITAD_ENCICLOPEDIA_H
