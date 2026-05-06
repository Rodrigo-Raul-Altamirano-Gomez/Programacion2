//
// Created by hrodic on 10/04/2026.
//

#include "FuncionesAuxiliares.h"

#include <iostream>

void CargarAlumnos(Alumnos* arrAlumnos) {
    int cont=0;
    ifstream archAlumnos;
    AperturaArchivoLectura(archAlumnos,"ArchivosDeEntrada/Alumnos.csv");
    while (true) {
        archAlumnos>>arrAlumnos[cont];
        if (archAlumnos.eof()) break;
        cont++;
    }
    arrAlumnos[cont].codigo=0;
}

void AperturaArchivoLectura(ifstream& archAlumnos,const char* nombreArchivo) {
    archAlumnos.open(nombreArchivo,ios::in);
    if (not archAlumnos.is_open()) cout<<"Error al abrir el archivo: "<<nombreArchivo<<endl;
}

void CargarCursos(Cursos* arrCursos) {
    int cont=0;
    ifstream archCursos;
    AperturaArchivoLectura(archCursos,"ArchivosDeEntrada/Cursos.csv");
    while (true) {
        archCursos>>arrCursos[cont];
        if (archCursos.eof()) break;
        cont++;
    }
    arrCursos[cont].codigo=nullptr;
}

void ProcesarMatricula(Alumnos* arrAlumnos,Cursos* arrCursos) {
    int posAlumno,posCurso;
    Alumnos alumno;
    Cursos curso;
    ifstream archMatricula;
    AperturaArchivoLectura(archMatricula,"ArchivosDeEntrada/Matricula.csv");
    while (true) {
        curso.codigo=LeeCadenaExacta(archMatricula,',');
        if (not curso.codigo) break;
        archMatricula>>alumno.codigo;
        archMatricula.ignore();
        posAlumno=arrAlumnos<=alumno;
        posCurso=arrCursos>=curso;
        if (posAlumno>=0 and posCurso>=0) arrCursos[posCurso]+=arrAlumnos[posAlumno];
        delete[] curso.codigo;
    }
}

void EmitirReporte(Cursos* arrCursos) {
    ofstream archReporte("ArchivosDeSalida/Reporte.txt",ios::out);
    if (not archReporte.is_open()) cout<<"El archivo de salida no existe"<<endl;
    for (int cont=0;arrCursos[cont].codigo;cont++) {
        arrCursos[cont]++;
        archReporte<<arrCursos[cont];
    }
}