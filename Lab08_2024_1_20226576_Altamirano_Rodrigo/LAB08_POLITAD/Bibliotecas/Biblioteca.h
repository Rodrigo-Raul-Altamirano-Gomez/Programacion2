//
// Created by hrodic on 14/06/2026.
//

#ifndef LAB08_POLITAD_BIBLIOTECA_H
#define LAB08_POLITAD_BIBLIOTECA_H
#include "Estante.h"
#include <fstream>
using namespace std;


class Biblioteca {
    Estante AEstantes[10];
    bool insertarLibro(Libro*);
public:
    void carga();
    void llena();
    void baja();
    void muestra() const;
};


#endif //LAB08_POLITAD_BIBLIOTECA_H
