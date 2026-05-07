//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB07_PREG01_CLASES_ALUMNOS_H
#define LAB07_PREG01_CLASES_ALUMNOS_H

#include "Nota.h"
#include <fstream>
using namespace std;

class Alumno {
    int codigo;
    char* nombre;
    int numCursos;
    int numAprobados;
    int numPrimera;
    int numSegunda;
    int numTercera;
    Nota lNotas[20];
public:
    friend ifstream& operator>>(ifstream&,Alumno&);
    void operator+=(const Nota&);
    friend ofstream& operator<<(ofstream&,const Alumno&);
};


#endif //LAB07_PREG01_CLASES_ALUMNOS_H
