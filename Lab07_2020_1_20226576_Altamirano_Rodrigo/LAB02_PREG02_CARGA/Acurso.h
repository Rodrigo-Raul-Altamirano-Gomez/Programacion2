//
// Created by hrodic on 10/05/2026.
//

#ifndef LAB02_PREG02_ALUMNO_ACURSO_H
#define LAB02_PREG02_ALUMNO_ACURSO_H

#include <fstream>
using namespace std;
#include "Curso.h"

class Alumno;

class Acurso {
    int codigo;
    Curso clcurso;
    char operacion;
public:
    const Curso getCurso() const;
    int buscarCurso(const Curso*,int) const;
    void setCodigo(int);
    void setCurso(const char*,int,int,double);
    void setOperacion(char);
    int getCodigo() const;
    int buscarAlumno(const Alumno*,int);
    char getOperacion() const;
};

ifstream& operator>>(ifstream&,Acurso&);

#endif //LAB02_PREG02_ALUMNO_ACURSO_H
