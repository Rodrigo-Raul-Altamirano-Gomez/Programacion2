//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG01_CLASES_INFRACCION_H
#define LAB07_PREG01_CLASES_INFRACCION_H

#include <fstream>
using namespace std;

class Infraccion {
    int codigo;
    char* descripcion;
    char* gravedad;
    double multa;
public:
    Infraccion();
    void setCodigo(int);
    void setDescripcion(const char*);
    void setGravedad(const char*);
    void setMulta(double);
    int getCodigo() const;
    const char* getGravedad() const;
    double getMulta() const;
    ~Infraccion();
};

ifstream& operator>>(ifstream&,Infraccion&);

#endif //LAB07_PREG01_CLASES_INFRACCION_H
