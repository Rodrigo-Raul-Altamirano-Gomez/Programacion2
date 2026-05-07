//
// Created by hrodic on 7/05/2026.
//

#ifndef LAB07_PREG02_CARGA_FUNCIONES_H
#define LAB07_PREG02_CARGA_FUNCIONES_H

#include "Alumno.h"
#include "AlumnoNota.h"

void CargarAlumnos(Alumno*);
void CargarNotas(AlumnoNota*);
void ActualizarNotas(Alumno*,AlumnoNota*);
int BuscarAlumno(Alumno*,int);
void ImprimirAlumnos(Alumno*);

#endif //LAB07_PREG02_CARGA_FUNCIONES_H
