//
// Created by hrodic on 19/04/2026.
//

#ifndef ACTIVIDAD05_FUNCIONESACTIVIDAD05_H
#define ACTIVIDAD05_FUNCIONESACTIVIDAD05_H

#include <fstream>
using namespace std;

void leerAlumnos(void*&);
bool LeeLineaAlumnos(void*&,ifstream&);
char* LeeCadenaExacta(ifstream&,char);
void imprimirAlumnos(const void*);
void leerCursos(void*);
bool LeeLineaCursos(int&,void*&,int&,double&,ifstream&);
int BuscarAlumno(int,void**);
void AñadirCursoAprobado(void*,void*&);
void consolidado(const void*);

#endif //ACTIVIDAD05_FUNCIONESACTIVIDAD05_H
