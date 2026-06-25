//
// Created by hrodic on 23/06/2026.
//

#ifndef LAB09_ABBSTL_BIBLIOTECA_H
#define LAB09_ABBSTL_BIBLIOTECA_H
#include "ABB.h"
#include "Estante.h"
#include <fstream>

class Biblioteca {
    ABB<Estante> AEstante;
public:
    void carga();
    void muestra();
    void prueba(double);
};


#endif //LAB09_ABBSTL_BIBLIOTECA_H
