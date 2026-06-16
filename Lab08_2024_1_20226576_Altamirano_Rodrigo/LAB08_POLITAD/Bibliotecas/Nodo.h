//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_NODO_H
#define LAB08_POLITAD_NODO_H
#include "Libro.h"


class Nodo {
    Libro* plibro;
    Nodo* sig;
    friend class Lista;
public:
    Nodo();
    ~Nodo();
};


#endif //LAB08_POLITAD_NODO_H
