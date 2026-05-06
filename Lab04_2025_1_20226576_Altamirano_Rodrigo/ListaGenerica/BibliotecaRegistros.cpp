//
// Created by hrodic on 27/04/2026.
//
#include <cstring>
#include <iomanip>
#include "BibliotecaRegistros.h"

bool leeregistro(void*& registro,ifstream& archFaltas) {
    int licencia;
    char car;
    if (archFaltas>>licencia) {
        int *licenciaFalta=new int(licencia),*tipoFalta=new int;
        archFaltas.ignore();
        archFaltas.ignore(20,',');
        char* fechaFalta=LeerCadenaExacta(archFaltas,',');
        archFaltas>>*tipoFalta>>car;
        char* nombreConductor=LeerCadenaExacta(archFaltas,'\n');
        registro=new void*[4]{licenciaFalta,fechaFalta,tipoFalta,nombreConductor};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archFaltas,char delim) {
    char *cadenaExacta,buffer[200];
    archFaltas.getline(buffer,200,delim);
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void clasificaregistro(void* registro,void* lista,void*& nodoBloque,void*& nodoOtroBloque) {
    void** regLista=(void**)lista;
    void** regFalta=(void**)registro;
    if ((*(int*)regFalta[2])/100==1) {
        nodoBloque=regLista[0];
        nodoOtroBloque=regLista[1];
    }
    else {
        nodoBloque=regLista[1];
        nodoOtroBloque=regLista[0];
    }
}

void imprimeregistro(void* registro,ofstream& archRepFaltas) {
    if (registro) {
        void** regFalta=(void**)registro;
        archRepFaltas<<left<<setw(12)<<(char*)regFalta[1]<<setw(12)<<*(int*)regFalta[0];
        archRepFaltas<<setw(50)<<(char*)regFalta[3]<<*(int*)regFalta[2]<<endl;
    }
}
