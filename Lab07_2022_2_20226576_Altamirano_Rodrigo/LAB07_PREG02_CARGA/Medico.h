//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG01_CLASES_MEDICO_H
#define LAB07_PREG01_CLASES_MEDICO_H

#include <fstream>
using namespace std;

class Medico {
    int codigo;
    char* nombre;
    double tarifa;
public:
    Medico();
    void setCodigo(int);
    void setNombre(const char*);
    void setTarifa(double);
    int getCodigo() const;
    double getTarifa() const;
    ~Medico();
};

ifstream& operator>>(ifstream&,Medico&);

#endif //LAB07_PREG01_CLASES_MEDICO_H
