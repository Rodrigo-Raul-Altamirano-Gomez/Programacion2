//
// Created by hrodic on 11/06/2026.
//

#ifndef PREG01_LAB09_BOLETA_H
#define PREG01_LAB09_BOLETA_H

#include <fstream>
#include "Alumno.h"
using namespace std;

class Boleta {
    Alumno* pboleta;
public:
    Boleta();
    int getEscalaAlumno() const;
    bool existe() const;
    void leer(ifstream&,int);
    void actualizar(double);
    void imprimir(ofstream&) const;
    ~Boleta();
};


#endif //PREG01_LAB09_BOLETA_H
