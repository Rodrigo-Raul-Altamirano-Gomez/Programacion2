//
// Created by hrodic on 29/04/2026.
//
#include <cstring>
#include <iomanip>
#include "BibliotecaConductores.h"

bool leeconductores(void*& conductor,ifstream& archConductores) {
    int licencia;
    if (archConductores>>licencia) {
        archConductores.ignore();
        char* nombreConductor=LeerCadenaExacta1(archConductores);
        int* licenciaConductor=new int(licencia);
        void* listaInfracciones=new void*(nullptr);
        conductor=new void*[4]{licenciaConductor,nombreConductor,nullptr,listaInfracciones};
        return true;
    }
    return false;
}

char* LeerCadenaExacta1(ifstream& archInfracciones) {
    char *cadenaExacta,buffer[200];
    archInfracciones.getline(buffer,200,'\n');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

int cmpconductores(void* conductor1,void* conductor2) {
    void** regConductor1=(void**)conductor1;
    void** regConductor2=(void**)conductor2;
    if (*(int*)regConductor1[0]>=*(int*)regConductor2[0]) return 1;
    else return -1;
}

void* buscalistaconductores(void* conductor,void* listaConductores) {
    void** regConductor=(void**)conductor;
    void** regLista=(void**)listaConductores;
    for (void** regNodoActual=(void**)*regLista;regNodoActual;regNodoActual=(void**)regNodoActual[1]) {
        void** regConductorActual=(void**)regNodoActual[0];
        if (*(int*)regConductorActual[0]==*(int*)regConductor[0]) return regConductorActual;
    }
    return nullptr;
}

void cargaUnidades(void* listaConductores,const char* nombreArchivoUnidades) {
    ifstream archUnidades(nombreArchivoUnidades,ios::in);
    void* placa;
    int licenciaConductor;
    while (leerLineaUnidades(licenciaConductor,placa,archUnidades)) {
        void* conductor=new void*[4]{&licenciaConductor};
        void** regConductor=(void**)buscalistaconductores(conductor,listaConductores);
        InsertarPlacaAlConductor(placa,regConductor[2]);
        delete[] (void**)conductor;
    }
}

bool leerLineaUnidades(int& licenciaConductor,void*& placa,ifstream& archUnidades) {
    if (archUnidades>>licenciaConductor) {
        archUnidades.ignore();
        char* placaConductor=LeerCadenaExacta1(archUnidades);
        placa=placaConductor;
        return true;
    }
    return false;
}

void InsertarPlacaAlConductor(void* placa,void*& placasConductor) {
    if (not placasConductor) placasConductor=new void*[2]{placa,nullptr};
    else {
        int cantPlacasConductor=0;
        void** regPlacasConductor=(void**)placasConductor;
        for (int i=0;regPlacasConductor[i];i++) cantPlacasConductor++;
        void** aux=new void*[cantPlacasConductor+2]{};
        for (int i=0;i<cantPlacasConductor;i++) aux[i]=regPlacasConductor[i];
        aux[cantPlacasConductor]=placa;
        delete[] regPlacasConductor;
        placasConductor=aux;
    }
}

void imprimeconductores(void* conductor,ofstream& archReporte) {
    void** regConductor=(void**)conductor;
    archReporte<<left<<setw(12)<<*(int*)regConductor[0]<<(char*)regConductor[1]<<endl;
    archReporte<<"Placas: ";
    void** regPlacasConductor=(void**)regConductor[2];
    for (int i=0;regPlacasConductor[i];i++) archReporte<<(char*)regPlacasConductor[i]<<" ";
    archReporte<<endl<<setw(12)<<"Fecha"<<setw(12)<<"Placa"<<"Infraccion"<<endl;
    void** regListaInfracciones=(void**)regConductor[3];
    for (void** regNodoInfraccion=(void**)*regListaInfracciones;regNodoInfraccion
        ;regNodoInfraccion=(void**)regNodoInfraccion[1]) {
        void** regInfraccion=(void**)regNodoInfraccion[0];
        archReporte<<setw(12)<<*(int*)regInfraccion[2]<<setw(12)<<(char*)regInfraccion[1];
        archReporte<<*(int*)regInfraccion[3]<<endl;
    }
}