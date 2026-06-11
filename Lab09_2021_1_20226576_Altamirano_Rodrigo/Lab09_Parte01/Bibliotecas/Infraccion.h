//
// Created by hrodic on 8/06/2026.
//

#ifndef INFRACCIONES2021_1LAB09_INFRACCION_H
#define INFRACCIONES2021_1LAB09_INFRACCION_H

#include <fstream>
using namespace std;

class Infraccion {
    int codigo;
    char* descripcion;
    double multa;
public:
    Infraccion();
    void setDescripcion(const char*);
    virtual void lee(ifstream&,int);
    virtual ~Infraccion();
};


#endif //INFRACCIONES2021_1LAB09_INFRACCION_H
