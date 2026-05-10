//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG01_CLASES_FALTA_H
#define LAB07_PREG01_CLASES_FALTA_H

#include <fstream>
using namespace std;

class Falta {
    int licencia;
    char* placa;
    int codInf;
    int fecha;
public:
    Falta();
    void setLicencia(int);
    void setPlaca(const char*);
    void setfecha(int);
    void setCodigo(int);
    const char* getPlaca() const;
    int getCodigo() const;
    int getFecha() const;
    int getLicencia() const;
    ~Falta();
};

ifstream& operator>>(ifstream&,Falta&);

#endif //LAB07_PREG01_CLASES_FALTA_H
