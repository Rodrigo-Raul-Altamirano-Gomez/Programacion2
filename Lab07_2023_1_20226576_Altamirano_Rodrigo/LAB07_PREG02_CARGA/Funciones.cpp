//
// Created by hrodic on 7/05/2026.
//
#include <fstream>
#include "Funciones.h"

using namespace std;

void CargarAlumnos(Alumno* arrAlumnos) {
    ifstream archAlumnos("Alumnos.csv",ios::in);
    int cantAlumnos=0;
    Alumno alumno;
    while (archAlumnos>>alumno) {
        alumno.inicializarCantidades();
        arrAlumnos[cantAlumnos]=alumno;
        cantAlumnos++;
    }
    Alumno alumnoAuxFin;
    alumnoAuxFin.setVacio();
    arrAlumnos[cantAlumnos]=alumnoAuxFin;
}

void CargarNotas(AlumnoNota* arrNotasAlumnos) {
    ifstream archNotas("Notas.csv",ios::in);
    int cantNotas=0;
    AlumnoNota notaAlumno;
    while (archNotas>>notaAlumno) {
        arrNotasAlumnos[cantNotas]=notaAlumno;
        cantNotas++;
    }
    AlumnoNota notaAlumnoAuxFin;
    notaAlumnoAuxFin.setVacio();
    arrNotasAlumnos[cantNotas]=notaAlumnoAuxFin;
}

void ActualizarNotas(Alumno* arrAlumnos,AlumnoNota* arrNotasAlumnos) {
    for (int i=0;i<200;i++) {
        int codAlumno=arrNotasAlumnos[i].getCodigo();
        if (codAlumno==0) break;
        int posAlumno=BuscarAlumno(arrAlumnos,codAlumno);
        if (posAlumno>=0) {
            Nota nota;
            arrNotasAlumnos[i]&nota;
            arrAlumnos[posAlumno].actulizarCantidades(nota);
            arrAlumnos[posAlumno]+=nota;
        }
    }
}

int BuscarAlumno(Alumno* arrAlumnos,int codAlumno) {
    for (int i=0;i<100;i++) {
        int codigoAlumno=arrAlumnos[i].getCodigo();
        if (codAlumno==0) break;
        if (codigoAlumno==codAlumno) return i;
    }
    return -1;
}

void ImprimirAlumnos(Alumno* arrAlumnos) {
    ofstream archReporte("Reporte.txt",ios::out);
    for (int i=0;arrAlumnos[i].getCodigo()!=0;i++) {
        archReporte<<arrAlumnos[i];
    }
}