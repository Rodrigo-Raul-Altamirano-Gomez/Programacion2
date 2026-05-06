//
// Created by hrodic on 10/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2025_2_OPERADORESSOBRECARGADOS_H
#define FUENTES_BIBLIOTECA_2025_2_OPERADORESSOBRECARGADOS_H

#include "Estructuras.h"
#include <fstream>
using namespace std;

void operator>> (ifstream&,Cursos&);
char* LeeCadenaExacta(ifstream&,char);
void operator>> (ifstream&,Alumnos&);
bool operator> (const Alumnos&,int);
bool operator> (const Cursos&,const char*);
void operator+= (Cursos&,const Alumnos&);
void AñadirAlumnosArrAlumnos(Alumnos*,int&,const Alumnos&);
int operator<= (Alumnos*,const Alumnos&);
int operator>= (Cursos*,const Cursos&);
void operator++ (Cursos&,int);
char* AsignarCadenaExacta(const char*);
void operator<< (ofstream&,const Cursos&);

#endif //FUENTES_BIBLIOTECA_2025_2_OPERADORESSOBRECARGADOS_H
