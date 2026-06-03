//
// Created by hrodic on 9/05/2026.
//

#ifndef LAB07_PREG01_CLASES_PACIENTE_H
#define LAB07_PREG01_CLASES_PACIENTE_H

#include "Cita.h"

class Paciente {
    int dni;
    char* nombre;
    Cita lcitas[100];
    int telefono;
    double totalgastado;
public:
    Paciente();
    void setDni(int);
    void setNombre(const char*);
    void setTelefono(int);
    Paciente& operator+=(const Cita&);
    Paciente& operator++(int);
    int getDni() const;
    const char* getNombre() const;
    int getTelefono() const;
    void imprimirCitas(ofstream&) const;
    double getTotal() const;
    ~Paciente();
};

ifstream& operator>>(ifstream&,Paciente&);
ofstream& operator<<(ofstream&,const Paciente&);

#endif //LAB07_PREG01_CLASES_PACIENTE_H
