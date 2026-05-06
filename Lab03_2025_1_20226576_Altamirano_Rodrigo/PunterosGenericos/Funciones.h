//
// Created by hrodic on 23/04/2026.
//

#ifndef PUNTEROSGENERICOS_FUNCIONES_H
#define PUNTEROSGENERICOS_FUNCIONES_H

#include <fstream>
#include "Tabla.h"
using namespace std;

void inicializar_tabla(Tabla&);
void insertar_columna(Tabla&,void*);
void IncrementarMemoriaPorIncrementos(void*&,int,int&,int);
void insertar_fila(Tabla&);
void insertar_campo(Tabla,void*,int,void*);
void cargar_tabla_infracciones(Tabla&);
bool LeerLineaInfracciones(int*&,char*&,char*&,double*&,ifstream&);
char* LeerCadenaExacta(ifstream&);
void** abrir_cursor(Tabla);
bool hay_siguiente(void*&);
void* obtener_campo(void*,int);
void recorrerCursor(Tabla);

#endif //PUNTEROSGENERICOS_FUNCIONES_H
