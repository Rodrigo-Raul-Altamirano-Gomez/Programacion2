//
// Created by hrodic on 11/06/2026.
//

#ifndef PREG01_LAB09_ALUMNO_H
#define PREG01_LAB09_ALUMNO_H

#include <fstream>
using namespace std;

class Alumno {
    int codigo;
    char* nombre;
    int escala;
    double creditos;
    double total;
public:
    Alumno();
    void setNombre(const char*);
    virtual void lee(ifstream&);
    virtual void imprime(ofstream&) const;
    virtual ~Alumno();
};


#endif //PREG01_LAB09_ALUMNO_H
