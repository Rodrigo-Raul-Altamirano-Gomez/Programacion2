//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_NOVELA_H
#define LAB08_POLITAD_NOVELA_H
#include "Libro.h"


class Novela : public Libro {
    char* autor;
public:
    Novela();
    void setAutor(const char*);
    void lee(ifstream &) override;
    void actualiza() override;
    void imprime(ofstream &) const override;
    ~Novela() override;
};


#endif //LAB08_POLITAD_NOVELA_H
