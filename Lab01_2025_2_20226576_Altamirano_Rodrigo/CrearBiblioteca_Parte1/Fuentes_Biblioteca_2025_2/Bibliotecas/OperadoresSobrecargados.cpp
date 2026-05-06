//
// Created by hrodic on 10/04/2026.
//

#include "OperadoresSobrecargados.h"
#include <cstring>
#include <iomanip>

void operator>> (ifstream& archLectura,Cursos& curso) {
    curso.codigo=LeeCadenaExacta(archLectura,',');
    if (curso.codigo) {
        curso.nombre=LeeCadenaExacta(archLectura,',');
        archLectura>>curso.creditos;
        archLectura.ignore();
        curso.docente=LeeCadenaExacta(archLectura,'\n');
        curso.numpresencial=0;
        curso.numsemipresencial=0;
        curso.numvirtual=0;
    }
}

char* LeeCadenaExacta(ifstream& archLectura,char delim) {
    char* cadenaExacta;
    char buffer[200];
    archLectura.getline(buffer,200,delim);
    if (archLectura.eof()) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void operator>> (ifstream& archLectura,Alumnos& alumno) {
    if (archLectura>>alumno.codigo) {
        archLectura.ignore();
        alumno.nombre=LeeCadenaExacta(archLectura,',');
        archLectura>>alumno.tipo;
    }
}

bool operator> (const Alumnos& alumno,int codigoAlumno) {
    if (alumno.codigo==codigoAlumno) return true;
    else return false;
}

bool operator> (const Cursos& curso,const char* codigoCurso) {
    if (strcmp(curso.codigo,codigoCurso)==0) return true;
    else return false;
}

void operator+= (Cursos& curso,const Alumnos& alumno) {
    if (alumno.tipo=='P') AñadirAlumnosArrAlumnos(curso.presencial,curso.numpresencial,alumno);
    else if (alumno.tipo=='S') AñadirAlumnosArrAlumnos(curso.semipresencial,curso.numsemipresencial,alumno);
    else AñadirAlumnosArrAlumnos(curso.vvirtual,curso.numvirtual,alumno);
}

void AñadirAlumnosArrAlumnos(Alumnos* alumnos,int& numAlumnos,const Alumnos& alumno) {
    alumnos[numAlumnos]=alumno;
    numAlumnos++;
}

int operator<= (Alumnos* arrAlumnos,const Alumnos& alumno) {
    for (int cont=0;arrAlumnos[cont].codigo!=0;cont++) {
        if (arrAlumnos[cont].codigo==alumno.codigo) return cont;
    }
    return -1;
}

int operator>= (Cursos* arrCursos,const Cursos& curso) {
    for (int cont=0;arrCursos[cont].codigo;cont++) {
        if (strcmp(arrCursos[cont].codigo,curso.codigo)==0) return cont;
    }
    return -1;
}

void operator++ (Cursos& curso,int) {
    int porcenAlumnosPresencial=curso.numpresencial*100/(curso.numsemipresencial+curso.numvirtual+curso.numpresencial);
    if (porcenAlumnosPresencial>=50) curso.tipofinal=AsignarCadenaExacta("La clase se dictara en aula.");
    else curso.tipofinal=AsignarCadenaExacta("La clase se dictara 100% virtual.");
}

char* AsignarCadenaExacta(const char* cadena) {
    char* cadenaExacta=new char[strlen(cadena)+1];
    strcpy(cadenaExacta,cadena);
    return cadenaExacta;
}

void operator<< (ofstream& archEscritura,const Cursos& curso) {
    archEscritura<<left<<setw(10)<<curso.codigo<<curso.nombre<<endl;
    archEscritura<<curso.docente<<endl;
    archEscritura<<setw(20)<<"Alumnos presenciales:"<<curso.numpresencial<<endl;
    archEscritura<<setw(20)<<"Alumnos semipresenciales:"<<curso.numsemipresencial<<endl;
    archEscritura<<setw(20)<<"Alumnos virtuales:"<<curso.numvirtual<<endl;
    archEscritura<<curso.tipofinal<<endl;
}