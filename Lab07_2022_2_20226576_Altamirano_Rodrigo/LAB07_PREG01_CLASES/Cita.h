//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG01_CLASES_CITA_H
#define LAB07_PREG01_CLASES_CITA_H

#include "Medico.h"

class Cita {
    int dni;
    int codigo;
    int fecha;
    double tarifa;
public:
    Cita();
    void setDni(int);
    void setCodigo(int);
    void setFecha(int);
    int getDni() const;
    double getTarifa() const;
    int getCodigo() const;
    int getFecha() const;
    Cita& operator<=(const Medico*);
};

ifstream& operator>>(ifstream&,Cita&);

#endif //LAB07_PREG01_CLASES_CITA_H
