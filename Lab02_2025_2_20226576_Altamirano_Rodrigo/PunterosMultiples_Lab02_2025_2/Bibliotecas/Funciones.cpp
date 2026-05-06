//
// Created by hrodic on 16/04/2026.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Funciones.h"


void cargarCategorias(const char* nombreArchivo,char***& categorias) {
    char** categoria;
    int cantCategorias=0,capacidad=0;
    ifstream archCategorias(nombreArchivo,ios::in);
    categorias=nullptr;
    while (LeeLineaCategoria(categoria,archCategorias)) {
        if (cantCategorias==capacidad) {
            capacidad+=5;
            IncrementarMemoriaChar(categorias,capacidad,cantCategorias);
        }
        categorias[cantCategorias]=categoria;
        cantCategorias++;
    }
}

bool LeeLineaCategoria(char**& categoria,ifstream& archCategorias) {
    char* codigo;
    char* nombre;
    char* descripcion;
    codigo=LeeCadenaExacta(archCategorias,',');
    if (not codigo) return false;
    nombre=LeeCadenaExacta(archCategorias,',');
    descripcion=LeeCadenaExacta(archCategorias,'\n');
    categoria=new char*[3]{codigo,nombre,descripcion};
    return true;
}

char* LeeCadenaExacta(ifstream& archCategorias,char delim) {
    char buffer[200];
    char* cadenaExacta;
    archCategorias.getline(buffer,200,delim);
    if (not archCategorias) return nullptr;
    cadenaExacta=new char[strlen(buffer)+1];
    strcpy(cadenaExacta,buffer);
    return cadenaExacta;
}

void IncrementarMemoriaChar(char***& ptrTripleChar,int capacidad,int cantidad) {
    if (not ptrTripleChar) ptrTripleChar=new char**[capacidad+1]{};
    else {
        char*** aux;
        aux=new char**[capacidad+1]{};
        for (int i=0;i<cantidad;i++) aux[i]=ptrTripleChar[i];
        delete[] ptrTripleChar;
        ptrTripleChar=aux;
    }
}

void cargarStreamers(const char* nombreArchivo,char***& streamers,int**& fechasPromedios
    ,long long**& tiempoRepSeguidores) {
    ifstream archStreamers(nombreArchivo,ios::in);
    char** streamer;
    int *fechaPromedio,capacidad=0,cantStreamers=0;
    long long* tiempoRepSeguidor;
    streamers=nullptr;
    fechasPromedios=nullptr;
    tiempoRepSeguidores=nullptr;
    while (LeerLineaStreamer(streamer,fechaPromedio,tiempoRepSeguidor,archStreamers)) {
        if (cantStreamers==capacidad) {
            capacidad+=5;
            IncrementarMemoriaChar(streamers,capacidad,cantStreamers);
            IncrementarMemoriaInt(fechasPromedios,capacidad,cantStreamers);
            IncrementarMemoriaLongLong(tiempoRepSeguidores,capacidad,cantStreamers);
        }
        streamers[cantStreamers]=streamer;
        fechasPromedios[cantStreamers]=fechaPromedio;
        tiempoRepSeguidores[cantStreamers]=tiempoRepSeguidor;
        cantStreamers++;
    }
}

bool LeerLineaStreamer(char**& streamer,int*& fechaPromedio,long long*& tiempoRepSeguidor,ifstream& archStreamers) {
    char *cuenta,*categoria,car;
    int fechaCreacion,fechaUltTransmision,promEspectadores,diaCreacion,mesCreacion,anioCreacion,diaUltTransmision,
    mesUltTransmision,anioUltTransmision;
    long long tiempoTotalRep,cantSeguidores;
    cuenta=LeeCadenaExacta(archStreamers,',');
    if (not cuenta) return false;
    archStreamers>>diaCreacion>>car>>mesCreacion>>car>>anioCreacion>>car>>diaUltTransmision>>car>>mesUltTransmision;
    archStreamers>>car>>anioUltTransmision>>car>>tiempoTotalRep>>car>>promEspectadores>>car>>cantSeguidores>>car;
    categoria=LeeCadenaExacta(archStreamers,'\n');
    fechaCreacion=diaCreacion+mesCreacion*100+anioCreacion*10000;
    fechaUltTransmision=diaUltTransmision+mesUltTransmision*100+anioUltTransmision*10000;
    streamer=new char*[2]{cuenta,categoria};
    fechaPromedio=new int[3]{fechaCreacion,fechaUltTransmision,promEspectadores};
    tiempoRepSeguidor=new long long[2]{tiempoTotalRep,cantSeguidores};
    return true;
}

void IncrementarMemoriaInt(int**& fechasPromedios,int capacidad,int cantStreamers) {
    if (not fechasPromedios) fechasPromedios=new int*[capacidad+1]{};
    else {
        int** aux=new int*[capacidad+1]{};
        for (int i=0;i<cantStreamers;i++) aux[i]=fechasPromedios[i];
        delete[] fechasPromedios;
        fechasPromedios=aux;
    }
}

void IncrementarMemoriaLongLong(long long**& fechasPromedios,int capacidad,int cantStreamers) {
    if (not fechasPromedios) fechasPromedios=new long long*[capacidad+1]{};
    else {
        long long** aux=new long long*[capacidad+1]{};
        for (int i=0;i<cantStreamers;i++) aux[i]=fechasPromedios[i];
        delete[] fechasPromedios;
        fechasPromedios=aux;
    }
}

void cargarComentarios(const char* nombreArchivo,char***& comentarios,char***& etiquetas) {
    int cantComentarios=0,capacidad=0;
    ifstream archComentarios(nombreArchivo,ios::in);
    char **comentario,**etiqueta;
    comentarios=nullptr;
    etiquetas=nullptr;
    while (LeeLineaComentario(comentario,etiqueta,archComentarios)) {
        if (cantComentarios==capacidad) {
            capacidad+=5;
            IncrementarMemoriaChar(comentarios,capacidad,cantComentarios);
            IncrementarMemoriaChar(etiquetas,capacidad,cantComentarios);
        }
        comentarios[cantComentarios]=comentario;
        etiquetas[cantComentarios]=etiqueta;
        cantComentarios++;
    }

}

bool LeeLineaComentario(char**& comentario,char**& etiqueta,ifstream& archComentarios) {
    char *usuario,*texto,*texto2;
    usuario=LeeCadenaExacta(archComentarios,',');
    if (not usuario) return false;
    texto=LeeCadenaExacta(archComentarios,'[');
    etiqueta=AsignacionExactaEtiqueta(archComentarios);
    texto2=LeeCadenaExacta(archComentarios,'\n');
    ConcatenarTexto(texto,texto2);
    comentario=new char*[2]{usuario,texto};
    return true;
}

char** AsignacionExactaEtiqueta(ifstream& archComentarios) {
    char *buffer[10],**etiquetaExacta,*etiquetasComentario;
    int cantEtiquetas=0;
    etiquetasComentario=LeeCadenaExacta(archComentarios,']');
    CargarBuffer(etiquetasComentario,buffer,cantEtiquetas);
    etiquetaExacta=new char*[cantEtiquetas+1];
    for (int i=0;i<=cantEtiquetas;i++) {
        if (i==cantEtiquetas) etiquetaExacta[i]=nullptr;
        else etiquetaExacta[i]=buffer[i];
    }
    return etiquetaExacta;
}

void CargarBuffer(char* etiquetasComentario,char** buffer,int& cantEtiquetas) {
    char carAnt;
    for (int i=0;etiquetasComentario[i];i++) {
        if (i==0 or carAnt==' ') {
            buffer[cantEtiquetas]=&etiquetasComentario[i];
            cantEtiquetas++;
        }
        carAnt=etiquetasComentario[i];
        if (etiquetasComentario[i]==' ') etiquetasComentario[i]='\0';
    }
}

void ConcatenarTexto(char*& texto,char*& texto2) {
    char* aux;
    aux=texto;
    texto=new char[strlen(texto)+strlen(texto2)+1];
    strcpy(texto,aux);
    strcat(texto,texto2);
    delete[] aux;
    delete[] texto2;
}

void imprimirReporte(const char* nombreArchivo,char*** categorias,char*** streamers,int** fechasPromedios
    ,long long** tiempoRepSeguidores,char*** comentarios,char*** etiquetas) {
    ofstream archReporte(nombreArchivo,ios::out);
    char** categoria;
    archReporte<<fixed<<setprecision(2);
    for (int i=0;categorias[i];i++) {
        categoria=categorias[i];
        archReporte<<"/"<<setfill('*')<<setw(120)<<categoria[1]<<setw(80)<<"/"<<setfill(' ')<<endl;
        archReporte<<left<<setw(15)<<"CUENTA"<<setw(15)<<"FECHA CREACION"<<setw(20)<<"FECHA ULT. STREAM.";
        archReporte<<setw(15)<<"TIEMPO REP."<<setw(15)<<"CANT. SEGUID."<<"ETIQUETAS"<<endl;
        archReporte<<setfill('=')<<setw(200)<<" "<<endl<<setfill(' ');
        ImprimirStreamers(categoria[0],streamers,fechasPromedios,tiempoRepSeguidores,comentarios,etiquetas,archReporte);
    }
}

void ImprimirStreamers(const char* codCategoria,char*** streamers,int** fechasPromedios,long long** tiempoRepSeguidores
    ,char*** comentarios,char*** etiquetas,ofstream& archReporte) {
    char** streamer;
    int* fechaPromedio;
    long long* tiempoRep;
    for (int i=0;streamers[i];i++) {
        streamer=streamers[i];
        fechaPromedio=fechasPromedios[i];
        tiempoRep=tiempoRepSeguidores[i];
        if (strcmp(streamer[1],codCategoria)==0) {
            archReporte<<left<<setw(15)<<streamer[0]<<right;
            ImprimirFecha(fechaPromedio[0],archReporte);
            archReporte<<setw(5)<<" ";
            ImprimirFecha(fechaPromedio[1],archReporte);
            archReporte<<setw(13)<<(double)tiempoRep[0]/(1000*3600*24)<<" (dias)"<<setw(15)<<tiempoRep[1];
            archReporte<<setw(10)<<" ";
            ImprimirEtiquetas(streamer[0],comentarios,etiquetas,archReporte);
        }
    }
}

void ImprimirFecha(int fecha,ofstream& archReporte) {
    int dia,mes,anio,res;
    char car='-';
    anio=fecha/10000;
    res=fecha%10000;
    mes=res/100;
    dia=res%100;
    archReporte<<setfill('0')<<setw(2)<<dia<<car<<setw(2)<<mes<<car<<anio<<setfill(' ');
}

void ImprimirEtiquetas(const char* cuentaStreamer,char*** comentarios,char*** etiquetas,ofstream& archReporte) {
    char **etiqueta,*etiquetaComentario,**comentario;
    int cantMenciones=0;
    for (int i=0;etiquetas[i];i++) {
        comentario=comentarios[i];
        etiqueta=etiquetas[i];
        for (int j=0;etiqueta[j];j++) {
            etiquetaComentario=etiqueta[j];
            if (strcmp(etiquetaComentario,cuentaStreamer)==0) {
                archReporte<<"["<<comentario[0]<<"] '"<<comentario[1]<<"' "<<endl;
                cantMenciones++;
                break;
            }
        }
    }
    if (cantMenciones==0) archReporte<<endl;
}