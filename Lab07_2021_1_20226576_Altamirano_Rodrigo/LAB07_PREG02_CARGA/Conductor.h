//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG01_CLASES_CONDUCTOR_H
#define LAB07_PREG01_CLASES_CONDUCTOR_H

#include "Falta.h"
#include "Infraccion.h"
#include <fstream>
#include "FaltaCond.h"
using namespace std;

class Conductor {
    int licencia;
    char* nombre;
    FaltaCond* lfaltas;
    int numFaltas;
    double montoTotal;
public:
    Conductor();
    void setLicencia(int);
    void setNombre(const char*);
    Conductor& operator+(const Falta&);
    Conductor& operator+(const Infraccion&);
    Conductor& operator++(int);
    Conductor& operator*(int);
    const char* getNombre() const;
    int getLicencia() const;
    void imprimirFaltas(ofstream&) const;
    int getNumFaltas() const;
    double getTotal() const;
    Conductor& operator=(const Conductor&);
    ~Conductor();
};

ifstream& operator>>(ifstream&,Conductor&);
ofstream& operator<<(ofstream&,const Conductor&);


#endif //LAB07_PREG01_CLASES_CONDUCTOR_H
