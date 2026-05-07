//
// Created by hrodic on 7/05/2026.
//
#include "FuncionesAuxliares.h"
#include <iomanip>
#include "Alumnos.h"

ifstream& operator>>(ifstream& archAlumnos,Alumno& alumno) {
    if (archAlumnos>>alumno.codigo) {
        archAlumnos.ignore();
        alumno.nombre=LeerCadenaExacta(archAlumnos);
        archAlumnos.ignore(50,'\n');
        alumno.numCursos=0;
        alumno.numAprobados=0;
        alumno.numPrimera=0;
        alumno.numSegunda=0;
        alumno.numTercera=0;
        for (int i=0;i<20;i++) alumno.lNotas[i].setCodigoCurso(nullptr);
        return archAlumnos;
    }
    return archAlumnos;
}

void Alumno::operator+=(const Nota& nota) {
    int posNota=0;
    int cantVecesCurso=ContarCurso(this->lNotas,nota.getCodigoCurso(),posNota);
    if (cantVecesCurso==0) this->numCursos++;
    if (nota.getNota()>=11) {
        this->numAprobados++;
        if (cantVecesCurso==0) this->numPrimera++;
        else if (cantVecesCurso==1) this->numSegunda++;
        else this->numTercera++;
    }
    Nota& nuevaNota=this->lNotas[posNota];
    nuevaNota.setCodigoCurso(nota.getCodigoCurso());
    nuevaNota.setCiclo(nota.getCiclo());
    nuevaNota.setNota(nota.getNota());
}

ofstream& operator<<(ofstream& archReporte,const Alumno& alumno) {
    archReporte<<"Codigo del alumno: "<<alumno.codigo<<endl;
    archReporte<<"Nombre del alumno: "<<alumno.nombre;
    archReporte<<"Detalle de cursos:"<<endl;
    archReporte<<left<<setw(10)<<"Cursados"<<setw(10)<<"Aprobados"<<setw(10)<<"1ra Vez"<<setw(10)<<"2da Vez";
    archReporte<<"3ra Vez"<<endl;
    archReporte<<right<<setw(5)<<alumno.numCursos<<setw(10)<<alumno.numAprobados<<setw(10)<<alumno.numPrimera;
    archReporte<<setw(10)<<alumno.numSegunda<<setw(10)<<alumno.numTercera<<endl;
    return archReporte;
}
