//
// Created by hrodic on 10/05/2026.
//
#include "Alumno.h"
#include "Acurso.h"

const Curso Acurso::getCurso() const {
    return this->clcurso;
}

int Acurso::buscarCurso(const Curso *arrCursos,int numCursos) const {
    for (int i=0;i<numCursos;i++) {
        if (arrCursos[i]==this->clcurso) return i;
    }
    return -1;
}

ifstream& operator>>(ifstream& archACursos,Acurso& cursoAlumno) {
    int codigoAlumno,nota,anio,semestre,ciclo;
    if (archACursos>>codigoAlumno) {
        char codigoCurso[20],operacion,car;
        double creditos;
        archACursos>>codigoCurso>>nota>>anio>>car>>semestre>>creditos>>operacion;
        ciclo=semestre+anio*10;
        cursoAlumno.setCodigo(codigoAlumno);
        cursoAlumno.setCurso(codigoCurso,nota,ciclo,creditos);
        cursoAlumno.setOperacion(operacion);
    }
    return archACursos;
}

void Acurso::setCodigo(int codigo) {
    this->codigo=codigo;
}

void Acurso::setCurso(const char *codigo, int nota, int ciclo, double creditos) {
    this->clcurso.setCodigo(codigo);
    this->clcurso.setCiclo(ciclo);
    this->clcurso.setNota(nota);
    this->clcurso.setCreditos(creditos);
}

int Acurso::getCodigo() const {
    return this->codigo;
}

void Acurso::setOperacion(char operacion) {
    this->operacion=operacion;
}

int Acurso::buscarAlumno(const Alumno *arrAlumnos, int cantAlumnos) {
    for (int i=0;i<cantAlumnos;i++) {
        if (arrAlumnos[i].getCodigo()==this->codigo) return i;
    }
    return -1;
}

char Acurso::getOperacion() const {
    return this->operacion;
}
