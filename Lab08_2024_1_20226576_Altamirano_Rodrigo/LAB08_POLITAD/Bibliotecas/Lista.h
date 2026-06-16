//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_LISTA_H
#define LAB08_POLITAD_LISTA_H
#include "Nodo.h"


class Lista {
    double peso;
    Nodo* ini;
public:
    Lista();
    double getPeso() const;
    void insertar(Libro*);
    void actualizar();
    void imprimir(ofstream&) const;
    ~Lista();
};


#endif //LAB08_POLITAD_LISTA_H
