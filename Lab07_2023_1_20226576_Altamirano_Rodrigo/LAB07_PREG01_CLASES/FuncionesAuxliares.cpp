//
// Created by hrodic on 7/05/2026.
//
#include <cstring>
#include "FuncionesAuxliares.h"

char* LeerCadenaExacta(ifstream& archLectura) {
    char *cadenaExacta,buffer[200];
    archLectura.getline(buffer,200,',');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

char* CopiarCadenaExacta(const char* cadena) {
    char* cadenaExacta=new char[strlen(cadena)+1];
    strcpy(cadenaExacta,cadena);
    return cadenaExacta;
}

int ContarCurso(const Nota* arrNotasAlumno,const char* codCurso,int& posNota) {
    int cantVeces=0;
    for (int i=0;i<20;i++) {
        if (not arrNotasAlumno[i].getCodigoCurso()) break;
        if (strcmp(arrNotasAlumno[i].getCodigoCurso(),codCurso)==0) cantVeces++;
        posNota++;
    }
    return cantVeces;
}