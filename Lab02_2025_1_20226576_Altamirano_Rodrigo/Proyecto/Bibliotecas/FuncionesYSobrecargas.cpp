//
// Created by hrodic on 17/04/2026.
//
#include <cstring>
#include <iomanip>
#include <iostream>
#include "FuncionesYSobrecargas.h"
#define TAM_BUFFER 200

void operator+=(Conductores& conductores,const char* nombreArchivo) {
    ifstream archConductores(nombreArchivo,ios::in);
    int dnisBuffer[TAM_BUFFER];
    char *nombresBufffer[TAM_BUFFER];
    CargarBuffersConductores(archConductores,dnisBuffer,nombresBufffer,conductores.cantidad);
    conductores.dnis=new int[conductores.cantidad];
    conductores.nombres=new char*[conductores.cantidad];
    for (int i=0;i<conductores.cantidad;i++) {
        conductores.dnis[i]=dnisBuffer[i];
        conductores.nombres[i]=nombresBufffer[i];
    }
}

void CargarBuffersConductores(ifstream& archConductores,int* dnisBuffer,char** nombresBufffer,int& cantidadConductores) {
    cantidadConductores=0;
    while (archConductores>>dnisBuffer[cantidadConductores]) {
        archConductores.ignore();
        nombresBufffer[cantidadConductores]=LeeCadenaExacta(archConductores,'\n');
        cantidadConductores++;
    }
}

char* LeeCadenaExacta(ifstream& archConductores,char delim) {
    char buffer[TAM_BUFFER],*cadenaExacta;
    archConductores.getline(buffer,200,delim);
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void operator+=(Infracciones& infracciones,const char* nombreArchivo) {
    ifstream archInfracciones(nombreArchivo,ios::in);
    int codigosBuffer[TAM_BUFFER];
    double valoresBuffer[TAM_BUFFER];
    char *descripcionesBuffer[TAM_BUFFER],*tiposBuffer[TAM_BUFFER];
    CargarBuffersInfracciones(archInfracciones,codigosBuffer,descripcionesBuffer,tiposBuffer,valoresBuffer
        ,infracciones.cantidad);
    infracciones.codigos=new int[infracciones.cantidad];
    infracciones.descripciones=new char*[infracciones.cantidad];
    infracciones.tipos=new char*[infracciones.cantidad];
    infracciones.valores=new double[infracciones.cantidad];
    for (int i=0;i<infracciones.cantidad;i++) {
        infracciones.codigos[i]=codigosBuffer[i];
        infracciones.descripciones[i]=descripcionesBuffer[i];
        infracciones.tipos[i]=tiposBuffer[i];
        infracciones.valores[i]=valoresBuffer[i];
    }
}

void CargarBuffersInfracciones(ifstream& archInfracciones,int* codigosBuffer,char** descripcionesBuffer
    ,char** tiposBuffer,double* valoresBuffer,int& cantidadInfracciones) {
    cantidadInfracciones=0;
    while (archInfracciones>>codigosBuffer[cantidadInfracciones]) {
        archInfracciones.ignore();
        descripcionesBuffer[cantidadInfracciones]=LeeCadenaExacta(archInfracciones,',');
        tiposBuffer[cantidadInfracciones]=LeeCadenaExacta(archInfracciones,',');
        archInfracciones>>valoresBuffer[cantidadInfracciones];
        cantidadInfracciones++;
    }
}

void cargar_faltas_de_los_conductores(Faltas& faltas) {
    ifstream archFaltas("ArchivosDeDatos/Faltas.csv",ios::in);
    char *placa;
    faltas.conductores+="ArchivosDeDatos/Conductores.csv";
    faltas.infracciones+="ArchivosDeDatos/Infracciones.csv";
    int dniConductor,posConductor,numPlacas[faltas.conductores.cantidad]{};
    faltas.placas=new char**[faltas.conductores.cantidad]{};
    faltas.capacidades=new int[faltas.conductores.cantidad]{};
    while (archFaltas>>dniConductor) {
        archFaltas.ignore();
        placa=LeeCadenaExacta(archFaltas,',');
        archFaltas.ignore(50,'\n');
        posConductor=BuscarConductor(dniConductor,faltas.conductores.dnis,faltas.conductores.cantidad);
        if (posConductor>=0) {
            AñadirPlaca(placa,faltas.placas[posConductor],faltas.capacidades[posConductor]
                ,numPlacas[posConductor]);
        }
    }
}

int BuscarConductor(int dniConductor,int* dnisConductores,int cantidadConductores) {
    for (int i=0;i<cantidadConductores;i++) {
        if (dnisConductores[i]==dniConductor) return i;
    }
    return -1;
}

void AñadirPlaca(char* placa,char**& placasConductor,int& capacidadPlacasConductor,int& numPlacasConductor) {
    bool placaRepetida;
    placaRepetida=BuscarPlaca(placa,placasConductor,numPlacasConductor);
    if (not placaRepetida) {
        if (numPlacasConductor==capacidadPlacasConductor) {
            IncrementarMemoriaPlacasConductor(placasConductor,capacidadPlacasConductor,numPlacasConductor);
        }
        placasConductor[numPlacasConductor]=placa;
        numPlacasConductor++;
    }
}

bool BuscarPlaca(const char* placa,char** placas,int numPlacas) {
    for (int i=0;i<numPlacas;i++) {
        if (strcmp(placas[i],placa)==0) return true;
    }
    return false;
}

void IncrementarMemoriaPlacasConductor(char**& placasConductor,int& capacidadPlacasConductor,int numPlacasConductor) {
    capacidadPlacasConductor+=2;
    if (not placasConductor) placasConductor=new char*[capacidadPlacasConductor+1]{};
    else {
        char** aux=new char*[capacidadPlacasConductor+1]{};
        for (int i=0;i<numPlacasConductor;i++) aux[i]=placasConductor[i];
        delete[] placasConductor;
        placasConductor=aux;
    }
}

void imprimir_faltas_de_los_conductores(const Faltas& faltas) {
    int cantPlacasConductor;
    char** placasConductor;
    ofstream archReporte("ArchivosDeReporte/Reporte.txt",ios::out);
    archReporte<<setfill('=')<<setw(75)<<" "<<setfill(' ')<<endl;
    archReporte<<left<<setw(10)<<"DNI"<<setw(50)<<"VEHICULOS"<<"CANT VEHICULOS"<<endl;
    archReporte<<setfill('-')<<setw(75)<<" "<<setfill(' ')<<endl;
    for (int i=0;i<faltas.conductores.cantidad;i++) {
        placasConductor=faltas.placas[i];
        cantPlacasConductor=0;
        if (placasConductor) {
            archReporte<<right<<setfill('0')<<setw(8)<<faltas.conductores.dnis[i]<<setfill(' ')<<setw(2)<<" ";
            archReporte<<left<<setw(50)<<faltas.conductores.nombres[i];
            for (int j=0;placasConductor[j];j++) cantPlacasConductor++;
            archReporte<<right<<setw(10)<<cantPlacasConductor<<endl;
        }
    }
}