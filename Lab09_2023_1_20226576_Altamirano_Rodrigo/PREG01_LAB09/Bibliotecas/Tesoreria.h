//
// Created by hrodic on 11/06/2026.
//

#ifndef PREG01_LAB09_TESORERIA_H
#define PREG01_LAB09_TESORERIA_H

#include <fstream>
#include "Boleta.h"
#include "Escala.h"
using namespace std;

class Tesoreria {
    Boleta lboleta[200];
    Escala lescala[20];
public:
    void cargarescalas();
    void cargaalumnos();
    void imprimeboleta();
};


#endif //PREG01_LAB09_TESORERIA_H
