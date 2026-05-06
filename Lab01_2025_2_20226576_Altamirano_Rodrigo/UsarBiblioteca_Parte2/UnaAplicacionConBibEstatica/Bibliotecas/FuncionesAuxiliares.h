//
// Created by hrodic on 10/04/2026.
//

#ifndef UNAAPLICACIONCONBIBESTATICA_FUNCIONESAUXILIARES_H
#define UNAAPLICACIONCONBIBESTATICA_FUNCIONESAUXILIARES_H

#include "OperadoresSobrecargados.h"

void CargarAlumnos(Alumnos*);
void AperturaArchivoLectura(ifstream&,const char*);
void CargarCursos(Cursos*);
void ProcesarMatricula(Alumnos*,Cursos*);
void EmitirReporte(Cursos*);

#endif //UNAAPLICACIONCONBIBESTATICA_FUNCIONESAUXILIARES_H
