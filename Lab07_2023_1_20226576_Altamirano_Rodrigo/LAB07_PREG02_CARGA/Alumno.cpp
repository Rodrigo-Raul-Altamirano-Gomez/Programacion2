//
// Created by hrodic on 7/05/2026.
//
#include "FuncionesAuxliares.h"
#include <iomanip>
#include "Alumno.h"

ifstream& operator>>(ifstream& archAlumnos,Alumno& alumno) {
    if (archAlumnos>>alumno.codigo) {
        archAlumnos.ignore();
        alumno.nombre=LeerCadenaExacta(archAlumnos);
        archAlumnos.ignore(50,'\n');
        return archAlumnos;
    }
    return archAlumnos;
}

void Alumno::operator+=(const Nota& nota) {
    int cantNotas=0;
    for (;this->lNotas[cantNotas].getCiclo()!=0;cantNotas++);
    Nota& nuevaNota=this->lNotas[cantNotas];
    nuevaNota.setCodigoCurso(nota.getCodigoCurso());
    nuevaNota.setCiclo(nota.getCiclo());
    nuevaNota.setNota(nota.getNota());
}

ofstream& operator<<(ofstream& archReporte,const Alumno& alumno) {
    archReporte<<"Codigo del alumno: "<<alumno.codigo<<endl;
    archReporte<<"Nombre del alumno: "<<alumno.nombre<<endl;
    archReporte<<"Detalle de cursos:"<<endl;
    archReporte<<left<<setw(10)<<"Cursados"<<setw(10)<<"Aprobados"<<setw(10)<<"1ra Vez"<<setw(10)<<"2da Vez";
    archReporte<<"3ra Vez"<<endl;
    archReporte<<right<<setw(5)<<alumno.numCursos<<setw(10)<<alumno.numAprobados<<setw(10)<<alumno.numPrimera;
    archReporte<<setw(10)<<alumno.numSegunda<<setw(10)<<alumno.numTercera<<endl;
    return archReporte;
}

void Alumno::inicializarCantidades() {
    this->numCursos=0;
    this->numAprobados=0;
    this->numPrimera=0;
    this->numSegunda=0;
    this->numTercera=0;
    for (int i=0;i<20;i++) this->lNotas[i].setCiclo(0);
}

void Alumno::setVacio() {
    this->codigo=0;
}

int Alumno::getCodigo() {
    return this->codigo;
}

void Alumno::actulizarCantidades(const Nota& nota) {
    bool yaAprobado=false;
    int cantVecesCurso=ContarCurso(this->lNotas,nota.getCodigoCurso(),yaAprobado);
    if (cantVecesCurso==0) this->numCursos++;
    if (nota.getNota()>=11) {
        this->numAprobados++;
        if (cantVecesCurso==0) this->numPrimera++;
        else if (cantVecesCurso==1) this->numSegunda++;
        else this->numTercera++;
    }
    if (yaAprobado) {
        if (cantVecesCurso==1) {
            this->numSegunda++;
            this->numPrimera--;
        }
        else {
            this->numTercera++;
            this->numSegunda--;
        }
    }
}
