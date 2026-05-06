//
// Created by hrodic on 17/04/2026.
//

#ifndef PROYECTO_FUNCIONESYSOBRECARGAS_H
#define PROYECTO_FUNCIONESYSOBRECARGAS_H

#include "Estructuras.h"
#include <fstream>
using namespace std;

void operator+=(Conductores&,const char*);
void CargarBuffersConductores(ifstream&,int*,char**,int&);
char* LeeCadenaExacta(ifstream&,char);
void operator+=(Infracciones&,const char*);
void CargarBuffersInfracciones(ifstream&,int*,char**,char**,double*,int&);
void cargar_faltas_de_los_conductores(Faltas&);
int BuscarConductor(int,int*,int);
void AñadirPlaca(char*,char**&,int&,int&);
bool BuscarPlaca(const char*,char**,int);
void IncrementarMemoriaPlacasConductor(char**&,int&,int);
void imprimir_faltas_de_los_conductores(const Faltas&);

#endif //PROYECTO_FUNCIONESYSOBRECARGAS_H
