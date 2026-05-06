//
// Created by hrodic on 19/04/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Bib_Func_Preg1.h"

void leerUsuario(void*& usuarios) {
    ifstream archUsuarios("Usuarios.csv",ios::in);
    void* bufferUsuarios[200];
    int numUsuarios=0;
    void* usuario;
    while (LeerLineaUsuarios(usuario,archUsuarios)) {
        bufferUsuarios[numUsuarios]=(void**)usuario;
        numUsuarios++;
    }
    usuarios=new void*[numUsuarios+1]{};
    for (int i=0;i<numUsuarios;i++) ((void**)usuarios)[i]=(void**)bufferUsuarios[i];
}

bool LeerLineaUsuarios(void*& usuario,ifstream& archUsuarios) {
    int* codUsuario=new int[1];
    char* nombre;
    if (archUsuarios>>*codUsuario) {
        archUsuarios.ignore();
        nombre=LeeCadenaExacta(archUsuarios,'\n');
        usuario=new void*[4]{codUsuario,nombre,nullptr,nullptr};
        return true;
    }
    return false;
}

char* LeeCadenaExacta(ifstream& archUsuarios,char delim) {
    char buffer[200],*cadenaExacta;
    archUsuarios.getline(buffer,200,delim);
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void imprimirUsuarios(void* usuarios) {
    ofstream archReporteUsuarios("ReporteUsuarios.txt",ios::out);
    void** regUsuarios=(void**)usuarios;
    archReporteUsuarios<<"USUARIOS DE LA BIBLIOTECA"<<endl;
    archReporteUsuarios<<left<<setw(5)<<"No."<<setw(12)<<"CODIGO"<<"NOMBRE"<<endl;
    for (int i=0;regUsuarios[i];i++) {
        void** regUsuario=(void**)(regUsuarios[i]);
        archReporteUsuarios<<right<<setw(2)<<i+1<<")  "<<left<<setw(12)<<*((int*)(regUsuario[0]));
        archReporteUsuarios<<(char*)(regUsuario[1])<<endl;
    }
}