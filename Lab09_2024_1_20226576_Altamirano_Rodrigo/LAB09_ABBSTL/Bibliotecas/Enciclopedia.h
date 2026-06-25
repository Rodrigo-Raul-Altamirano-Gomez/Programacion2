//
// Created by hrodic on 23/06/2026.
//

#ifndef LAB09_ABBSTL_ENCICLOPEDIA_H
#define LAB09_ABBSTL_ENCICLOPEDIA_H
#include "Libro.h"


class Enciclopedia : public Libro {
    int sku;
    int anho;
public:
    Libro* clonar() const override;
    void leer(std::ifstream &) override;
    void imprimir(std::ofstream &) const override;
};


#endif //LAB09_ABBSTL_ENCICLOPEDIA_H
