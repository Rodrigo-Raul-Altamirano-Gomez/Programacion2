//
// Created by hrodic on 23/04/2026.
//
#include <cstring>
#include <iostream>
#include "Funciones.h"

void inicializar_tabla(Tabla& tabla) {
    tabla.filas=nullptr;
    tabla.columnas=nullptr;
    tabla.cantidad_filas=0;
    tabla.capacidad_filas=0;
    tabla.cantidad_columnas=0;
    tabla.capacidad_columnas=0;
}

void insertar_columna(Tabla& tabla,const char* tipoNuevoCampo) {
    if (tabla.cantidad_columnas==tabla.capacidad_columnas) {
        IncrementarMemoriaPorIncrementos(tabla.columnas,tabla.cantidad_columnas,tabla.capacidad_columnas
            ,2);
    }
    char* nuevoCampo=new char[strlen(tipoNuevoCampo)+1];
    strcpy(nuevoCampo,tipoNuevoCampo);
    void** regColumnas=(void**)tabla.columnas;
    regColumnas[tabla.cantidad_columnas]=nuevoCampo;
    tabla.cantidad_columnas++;
}

void IncrementarMemoriaPorIncrementos(void*& columnasOFilas,int cantidad,int& capacidad,int incremento) {
    capacidad+=incremento;
    if ( not columnasOFilas) columnasOFilas=new void*[capacidad]{};
    else {
        void** aux=new void*[capacidad]{};
        void** regColumnasOFilas=(void**)columnasOFilas;
        for (int i=0;i<cantidad;i++) aux[i]=regColumnasOFilas[i];
        delete[] regColumnasOFilas;
        columnasOFilas=aux;
    }
}

void insertar_fila(Tabla& tabla) {
    tabla.cantidad_filas++;
    if (tabla.cantidad_filas-1==tabla.capacidad_filas) {
        IncrementarMemoriaPorIncrementos(tabla.filas,tabla.cantidad_filas-1,tabla.capacidad_filas
            ,5);
    }
    void** regFilas=(void**)tabla.filas;
    regFilas[tabla.cantidad_filas-1]=new void*[tabla.cantidad_columnas]{};
}

void insertar_campo(Tabla tabla,void* fila,int numCampo,void* dato) {
    void** regFila=(void**)fila;
    regFila[numCampo-1]=dato;
}

void cargar_tabla_infracciones(Tabla& tabla) {
    ifstream archInfracciones("infracciones.csv",ios::in);
    int* codInfraccion;
    double* multaInfraccion;
    char *descripcionInfraccion,*tipoInfraccion;
    inicializar_tabla(tabla);
    insertar_columna(tabla,"INT");
    insertar_columna(tabla,"VARCHAR");
    insertar_columna(tabla,"VARCHAR");
    insertar_columna(tabla,"DOUBLE");
    while (LeerLineaInfracciones(codInfraccion,descripcionInfraccion,tipoInfraccion,multaInfraccion
        ,archInfracciones)) {
        insertar_fila(tabla);
        void** regFilas=(void**)tabla.filas;
        insertar_campo(tabla,regFilas[tabla.cantidad_filas-1],1,codInfraccion);
        insertar_campo(tabla,regFilas[tabla.cantidad_filas-1],2,descripcionInfraccion);
        insertar_campo(tabla,regFilas[tabla.cantidad_filas-1],3,tipoInfraccion);
        insertar_campo(tabla,regFilas[tabla.cantidad_filas-1],4,multaInfraccion);
    }
}

bool LeerLineaInfracciones(int*& codInfraccion,char*& descripcionInfraccion,char*& tipoInfraccion
    ,double*& multaInfraccion,ifstream& archInfracciones) {
    int codigo;
    if (archInfracciones>>codigo) {
        codInfraccion=new int(codigo);
        multaInfraccion=new double;
        archInfracciones.ignore();
        descripcionInfraccion=LeerCadenaExacta(archInfracciones);
        tipoInfraccion=LeerCadenaExacta(archInfracciones);
        archInfracciones>>*multaInfraccion;
        return true;
    }
    return false;
}

char* LeerCadenaExacta(ifstream& archInfracciones) {
    char *cadenaExacta,buffer[200];
    archInfracciones.getline(buffer,200,';');
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void** abrir_cursor(Tabla tabla) {
    if (tabla.filas) {
        void** regFilas=(void**)tabla.filas;
        return regFilas;
    }
    else return nullptr;
}

bool hay_siguiente(void*& cursor) {
    static int cantInvocaciones=0;
    cantInvocaciones++;
    if (cantInvocaciones==1) {
        if (cursor) return true;
        else return false;
    }
    else {
        void** regCursor=(void**)cursor;
        cursor=regCursor+1;
        if (cursor) return true;
        else return false;
    }
}

void* obtener_campo(void* cursor,int numCampo) {
    void** regCursor=(void**)cursor;
    void** regFila=(void**)(*regCursor);
    return regFila[numCampo-1];
}

void recorrerCursor(Tabla tabla) {
    void* cursor=abrir_cursor(tabla);
    while (hay_siguiente(cursor)) {
        int codigo=*(int*)obtener_campo(cursor,1);
        char* descripcion=(char*)obtener_campo(cursor,2);
        char* tipo=(char*)obtener_campo(cursor,3);
        int multa=*(double*)obtener_campo(cursor,4);
        cout<<codigo<<";"<<descripcion<<";"<<tipo<<";"<<multa<<endl;
    }
}
