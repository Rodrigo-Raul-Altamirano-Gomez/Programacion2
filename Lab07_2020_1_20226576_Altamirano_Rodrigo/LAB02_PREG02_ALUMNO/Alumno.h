//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB02_PREG02_ALUMNO_ALUMNO_H
#define LAB02_PREG02_ALUMNO_ALUMNO_H

#include "Acurso.h"
#include "Curso.h"

class Alumno {
    int codigo;
    char tipo;
    char* nombre;
    Curso* lcurso;
    int numcur;
public:
    Alumno();
    Alumno& operator+(const Acurso&);
    Alumno& operator*(const Acurso&);
    Alumno& operator-(const Acurso&);
    double operator/(int) const;
    double operator--() const;
    double operator++() const;
    void setCodigo(int);
    void setTipo(char);
    void setNombre(const char*);
    const char* getNombre() const;
    int getCodigo() const;
    void imprimirCursos(ofstream&) const;
    ~Alumno();
};

ifstream& operator>>(ifstream&,Alumno&);
ofstream& operator<<(ofstream&,const Alumno&);

#endif //LAB02_PREG02_ALUMNO_ALUMNO_H
