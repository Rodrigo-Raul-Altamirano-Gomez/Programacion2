//
// Created by hrodic on 10/05/2026.
//
#include <iomanip>
#include "Funciones.h"

void cargarAlumnos(Alumno*& arrAlumnos,int& cantAlumnos) {
    ifstream archAlumnos("Alumnos.txt",ios::in);
    Alumno bufferAlumnos[40];
    cantAlumnos=0;
    while (archAlumnos>>bufferAlumnos[cantAlumnos]) cantAlumnos++;
    arrAlumnos=new Alumno[cantAlumnos];
    for (int i=0;i<cantAlumnos;i++) arrAlumnos[i]=bufferAlumnos[i];
}

void procesarNotas(Alumno* arrAlumnos,int cantAlumnos) {
    ifstream archNotas("Cursos.txt",ios::in);
    Acurso cursoAlumno;
    while (archNotas>>cursoAlumno) {
        int posAlumno=cursoAlumno.buscarAlumno(arrAlumnos,cantAlumnos);
        if (posAlumno>=0) arrAlumnos[posAlumno]+cursoAlumno;
    }
}

void actualizarAlumnos(Alumno* arrAlumnos,int cantAlumnos) {
    ifstream archCorrecciones("Correcciones.txt",ios::in);
    Acurso cursoAlumno;
    while (archCorrecciones>>cursoAlumno) {
        int posAlumno=cursoAlumno.buscarAlumno(arrAlumnos,cantAlumnos);
        if (posAlumno>=0) {
            if (cursoAlumno.getOperacion()=='N') arrAlumnos[posAlumno]+cursoAlumno;
            else if (cursoAlumno.getOperacion()=='A') arrAlumnos[posAlumno]*cursoAlumno;
            else arrAlumnos[posAlumno]-cursoAlumno;
        }
    }
}

void emitirReporte(const Alumno* arrAlumnos,int cantAlumnos) {
    ofstream archReporte("Reporte.txt",ios::out);
    archReporte<<fixed<<setprecision(2);
    for (int i=0;i<cantAlumnos;i++) {
        archReporte<<arrAlumnos[i];
    }
}