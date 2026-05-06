//
// Created by hrodic on 29/04/2026.
//
#include <cstring>
#include "BibliotecaInfracciones.h"


bool leeinfracciones(void*& infraccion,ifstream& archInfracciones) {
    int licencia,diaInfraccion,mesInfraccion,anioInfraccion;
    char car;
    if (archInfracciones>>licencia) {
        int *licenciaConductor=new int(licencia),*fechaInfraccion=new int,*tipoInfraccion=new int();
        archInfracciones.ignore();
        char* placaInfraccion=LeerCadenaExacta(archInfracciones);
        archInfracciones>>diaInfraccion>>car>>mesInfraccion>>car>>anioInfraccion>>car>>*tipoInfraccion;
        *fechaInfraccion=diaInfraccion+mesInfraccion*100+anioInfraccion*10000;
        infraccion=new void*[4]{licenciaConductor,placaInfraccion,fechaInfraccion,tipoInfraccion};
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archInfracciones) {
    char *cadenaExacta,buffer[200];
    archInfracciones.getline(buffer,200,',');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

int cmpinfracciones(void* infraccion1,void* infraccion2) {
    void** regInfraccion1=(void**)infraccion1;
    void** regInfraccion2=(void**)infraccion2;
    if (*(int*)regInfraccion1[2]>=*(int*)regInfraccion2[2]) return 1;
    else return -1;
}

void* buscalistainfraccion(void* infraccion,void* listaConductores) {
    void** regInfraccion=(void**)infraccion;
    void** regLista=(void**)listaConductores;
    for (void** regNodoActual=(void**)*regLista;regNodoActual;regNodoActual=(void**)regNodoActual[1]) {
        void** regConductorActual=(void**)regNodoActual[0];
        if (*(int*)regConductorActual[0]==*(int*)regInfraccion[0]) return regConductorActual;
    }
    return nullptr;
}
