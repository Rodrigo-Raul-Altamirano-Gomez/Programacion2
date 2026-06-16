//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_ESTANTE_H
#define LAB08_POLITAD_ESTANTE_H
#include "Lista.h"
#include <fstream>
using namespace std;

class Estante {
    char clase;
    int id;
    double capacidad;
    Lista Llibros;
public:
    Estante();
    int getID() const;
    double getCapacidad() const;
    double getPeso() const;
    bool leer(ifstream&);
    void insertarLibro(Libro*);
    void actualizarVigencia();
    void imprimir(ofstream&) const;
};


#endif //LAB08_POLITAD_ESTANTE_H
