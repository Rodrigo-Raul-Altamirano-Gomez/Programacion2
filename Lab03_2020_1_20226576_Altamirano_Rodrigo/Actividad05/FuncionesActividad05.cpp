//
// Created by hrodic on 19/04/2026.
//
#include <cstring>
#include <iomanip>
#include "FuncionesActividad05.h"

void leerAlumnos(void*& alumnos) {
    ifstream archAlumnos("Alumnos.csv",ios::in);
    void *buffer[30],*alumno;
    int cantAlumnos=0;
    while (LeeLineaAlumnos(alumno,archAlumnos)) {
        buffer[cantAlumnos]=(void**)alumno;
        cantAlumnos++;
    }
    alumnos=new void*[cantAlumnos+1];
    for (int i=0;i<cantAlumnos;i++) ((void**)alumnos)[i]=buffer[i];
    ((void**)alumnos)[cantAlumnos]=nullptr;
}

bool LeeLineaAlumnos(void*& alumno,ifstream& archAlumnos) {
    char car;
    if (archAlumnos>>car) {
        int *codAlumno=new int,*acumuladoresInt=new int[2]{};
        double* acumuladoresDouble=new double[2]{};
        char* nombreAlumno;
        archAlumnos>>car>>*codAlumno>>car;
        nombreAlumno=LeeCadenaExacta(archAlumnos,',');
        archAlumnos.ignore(200,'\n');
        alumno=new void*[7]{codAlumno,nombreAlumno,acumuladoresDouble,acumuladoresDouble+1,acumuladoresInt
            ,acumuladoresInt+1,nullptr};
        return true;
    }
    return false;
}

char* LeeCadenaExacta(ifstream& archAlumnos,char delim) {
    char *cadenaExacta,buffer[200];
    archAlumnos.getline(buffer,200,delim);
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void imprimirAlumnos(const void* alumnos) {
    void** regAlumnos=(void**)alumnos;
    ofstream archReporteAlumnos("ReporteAlumnos.txt",ios::out);
    for (int i=0;regAlumnos[i];i++) {
        void** regAlumno=(void**)regAlumnos[i];
        archReporteAlumnos<<left<<setw(20)<<"Codigo:"<<setw(12)<<*((int*)(regAlumno[0]))<<setw(10)<<"Nombre:";
        archReporteAlumnos<<(char*)(regAlumno[1])<<endl;
    }
}

void leerCursos(void* alumnos) {
    void** regAlumnos=(void**)alumnos,*cursoAprobado;
    ifstream archCursos("Cursos.csv",ios::in);
    int codAlumno,notaCurso,posAlumno;
    double creditosCurso;
    while (LeeLineaCursos(codAlumno,cursoAprobado,notaCurso,creditosCurso,archCursos)) {
        posAlumno=BuscarAlumno(codAlumno,regAlumnos);
        if (posAlumno>=0) {
            void** regAlumno=(void**)(regAlumnos[posAlumno]);
            *((double*)(regAlumno[2]))+=creditosCurso;
            (*((int*)(regAlumno[4])))++;
            *((int*)(regAlumno[5]))+=notaCurso;
            if (notaCurso>=11) {
                *((double*)(regAlumno[3]))+=creditosCurso;
                AñadirCursoAprobado(cursoAprobado,regAlumno[6]);
            }
            else delete[] (char*)cursoAprobado;
        }
        else delete[] (char*)cursoAprobado;
    }
}

bool LeeLineaCursos(int& codAlumno,void*& cursoAprobado,int& notaCurso,double& creditosCurso,ifstream& archCursos) {
    if (archCursos>>codAlumno) {
        char *codCurso,car;
        archCursos.ignore();
        codCurso=LeeCadenaExacta(archCursos,',');
        archCursos>>notaCurso>>car;
        archCursos.ignore(20,',');
        archCursos>>creditosCurso;
        archCursos.ignore(20,'\n');
        cursoAprobado=codCurso;
        return true;
    }
    return false;
}

int BuscarAlumno(int codAlumno,void** regAlumnos) {
    for (int i=0;regAlumnos[i];i++) {
        void** regAlumno=(void**)(regAlumnos[i]);
        if (codAlumno==*((int*)(regAlumno[0]))) return i;
    }
    return -1;
}

void AñadirCursoAprobado(void* cursoAprobado,void*& cursosAprobados) {
    int cantCursosAprobados=0;
    if (not cursosAprobados) cursosAprobados=new void*[2]{cursoAprobado,nullptr};
    else {
        void** regCursosAprobados=(void**)cursosAprobados;
        for (int i=0;regCursosAprobados[i];i++) cantCursosAprobados++;
        void** aux=new void*[cantCursosAprobados+2]{};
        for (int i=0;i<cantCursosAprobados;i++) aux[i]=regCursosAprobados[i];
        aux[cantCursosAprobados]=cursoAprobado;
        delete[] regCursosAprobados;
        cursosAprobados=aux;
    }
}

void consolidado(const void* alumnos) {
    ofstream archReporteCompleto("ReporteCompleto.txt",ios::out);
    void** regAlumnos=(void**)alumnos;
    archReporteCompleto<<fixed<<setprecision(1)<<left;
    for (int i=0;regAlumnos[i];i++) {
        void** regAlumno=(void**)(regAlumnos[i]);
        archReporteCompleto<<setw(20)<<"Codigo:"<<setw(12)<<*((int*)(regAlumno[0]))<<setw(10)<<"Nombre:";
        archReporteCompleto<<setw(40)<<(char*)(regAlumno[1])<<"Cred.: "<<*((double*)(regAlumno[2]))<<" Cred. Apro.: ";
        archReporteCompleto<<*((double*)(regAlumno[3]))<<" Prom. Gene.: ";
        if (*((int*)(regAlumno[4]))!=0) archReporteCompleto<<(*((int*)(regAlumno[5])))/(*((int*)(regAlumno[4])));
        else archReporteCompleto<<0;
        archReporteCompleto<<endl<<setw(20)<<"Cursos Aprobados:";
        if (regAlumno[6]) {
            void** regCursosAprobados=(void**)(regAlumno[6]);
            for (int i=0;regCursosAprobados[i];i++) archReporteCompleto<<setw(10)<<(char*)(regCursosAprobados[i]);
        }
        else archReporteCompleto<<"Sin cursos aprobados";
        archReporteCompleto<<endl<<endl;
    }
}